<?php
/**
 * @file
 * This file handles updating the message listing.
 */

/**
 * Retrieves the list of folders.
 *
 * @param string $folder
 *   The name of the folder to open. If no folder is specified, the default
 *   of 'INBOX' is used.
 *
 * @return array
 *   The folder listing.
 */
function _basic_webmail_get_folder_list($folder = 'INBOX') {
  // Connect to the server and retrieve a connection to the mailbox.
  include_once drupal_get_path('module', 'basic_webmail') . '/basic_webmail.common.inc';
  global $user;
  $imap_resource = _basic_webmail_connect_to_server($user->uid, $folder);
  if ($imap_resource === FALSE) {
    $message = 'There was an error connecting to the mail server. Contact the system administrator and/or check the logs for more information.';
    _basic_webmail_report_error($message, array(), WATCHDOG_ERROR, TRUE);
    return FALSE;
  }

  // Get the list of folders from the server.
  $folders = imap_list($imap_resource, _basic_webmail_get_server_string(), '*');
  if (!empty($folders)) {
    natsort($folders);
    foreach ($folders as $folder_name) {
      $brief_folder_name = imap_utf7_decode(drupal_substr($folder_name, strpos($folder_name, '}') + 1, drupal_strlen($folder_name)));
//dpm($folder_name, '$folder_name');
//dpm($brief_folder_name, '$brief_folder_name');

      if ($brief_folder_name != $folder) {
        $folder_list[$brief_folder_name] = $brief_folder_name;
      }
    }
  }

  // Clean up.
  if (!imap_close($imap_resource)) {
    $message = 'There was an error closing the IMAP stream.';
    _basic_webmail_report_error($message, array(), WATCHDOG_WARNING);
  }

  return $folder_list;
}


/**
 * Updates the saved message list information.
 *
 * @param string $folder
 *   The name of the folder to open. If no folder is specified, the default
 *   of 'INBOX' is used.
 */
function _basic_webmail_update_stored_message_list($folder = 'INBOX') {
  // Connect to the server and retrieve a connection to the mailbox.
  include_once drupal_get_path('module', 'basic_webmail') . '/basic_webmail.common.inc';
  global $user;
  $imap_resource = _basic_webmail_connect_to_server($user->uid, $folder);
  if (empty($imap_resource)) {
    $message = 'There was an error connecting to the mail server. Contact the system administrator and/or check the logs for more information.';
    _basic_webmail_report_error($message, array(), WATCHDOG_ERROR, TRUE);
    return;
  }

  // Get the list of mailboxes.
  $mailboxes = imap_getsubscribed($imap_resource, _basic_webmail_get_server_string(), '*');
  if (empty($mailboxes[4])) {
    // Subscribe to any mailboxes that are not already subscribed.
    _basic_webmail_subscribe_to_mailboxes($user->uid);
  }
  // Add the mailbox names to the database.
  if (!empty($mailboxes)) {
    foreach ($mailboxes as $mailbox) {
      $brief_mailbox_name = imap_utf7_decode(drupal_substr($mailbox->name, strpos($mailbox->name, '}') + 1, drupal_strlen($mailbox->name)));
      if (!empty($brief_mailbox_name) && $brief_mailbox_name != $folder) {
        $results = db_query("SELECT fid FROM {basic_webmail_folders} WHERE user_id = :user_id AND folder_name = :folder_name",
          array(':user_id' => $user->uid, ':folder_name' => $brief_mailbox_name))->fetchField();
        if (empty($results)) {
          db_insert('basic_webmail_folders')
            ->fields(array(
              'user_id' => $user->uid,
              'folder_name' => $brief_mailbox_name,
            ))
            ->execute();
        }
      }
    }
  }

  // Remove the existing saved messages.
  $query = "DELETE FROM {basic_webmail_messages} WHERE user_id = :uid";
  db_query($query, array(':uid' => $user->uid));

  if (imap_num_msg($imap_resource) > 0) {
    // Retrieve and display the mail in the current folder.
    $threads = imap_thread($imap_resource);
    if ($threads === FALSE) {
      // Report the error.
      $message = t('There was an error getting the list of messages.');
      _basic_webmail_report_error($message, array(), WATCHDOG_ERROR, TRUE);
      return;
    }
    else {
      // Save the message information in a temporary table.
      foreach ($threads as $key => $message_number) {
        $tree = explode('.', $key);
        if ($tree[1] == 'num' && $message_number > 0) {
          // Get the messages information from the header.
          $message_header = imap_headerinfo($imap_resource, $message_number);

          // Make sure the message is not marked as deleted.
          if ($message_header->Deleted != 'D') {
            // Set the read status.
            if ($message_header->Recent == 'N' || $message_header->Unseen == 'U') {
              $message_unread = 1;
            }
            else {
              $message_unread = 0;
            }

            // Process the message's subject for storage in the database.
            if (!empty($message_header->subject)) {
              $message_subject = _basic_webmail_process_subject($message_header->subject, $message_unread, $message_number, $folder);
            }
            else {
              $message_subject = _basic_webmail_process_subject('(No subject specified)', $message_unread, $message_number, $folder);
            }

            // Process the message sender for storage in the database.
            if (empty($message_header->from[0])) {
              $from = array(
                'address' => '(Unknown)',
                'persona' => '(Unknown)',
              );
            }
            else {
              $from = _basic_webmail_process_from_address($message_header->from[0]);
            }

            // Set the message's date.
            if (empty($message_header->date)) {
              $message_date = 0;
            }
            else {
              $message_date = strtotime($message_header->date);
            }

            // Check if message was answered.
            if ($message_header->Answered == 'A') {
              $message_answered = 1;
            }
            else {
              $message_answered = 0;
            }

            // Check for attachments.
            // Get the message parts list.
            $parts_list = _basic_webmail_get_parts_list($imap_resource, $message_number);
            if (!empty($parts_list)) {
              // Iterate over the parts list.
              foreach ($parts_list as $part_array) {
                if (!empty($part_array[0]) && !empty($part_array[1])) {
                  $attachment_exists = 1;
                  continue;
                }
                else {
                  $attachment_exists = 0;
                }
              }
            }

            $query = "INSERT INTO {basic_webmail_messages}
              (user_id,
              message_number,
              message_subject,
              from_address,
              from_persona,
              message_date,
              message_unread,
              attachment_exists,
              message_answered,
              folder_name)
              VALUES(
              :user_id,
              :message_number,
              :message_subject,
              :from_address,
              :from_persona,
              :message_date,
              :message_unread,
              :attachment_exists,
              :message_answered,
              :folder_name
            )";
            $results = db_query($query, array(
              ':user_id' => $user->uid,
              ':message_number' => $message_number,
              ':message_subject' => iconv('UTF-8', 'ISO-8859-1//TRANSLIT', $message_subject),
              ':from_address' => iconv('UTF-8', 'ISO-8859-1//TRANSLIT', $from['address']),
              ':from_persona' => iconv('UTF-8', 'ISO-8859-1//TRANSLIT', $from['persona']),
              ':message_date' => $message_date,
              ':message_unread' => $message_unread,
              ':message_answered' => $message_answered,
              ':attachment_exists' => $attachment_exists,
              ':folder_name' => $folder,
            ));
          }
        }
      }
    }
  }

  // Clean up.
  if (!imap_close($imap_resource)) {
    $message = 'There was an error closing the IMAP stream.';
    _basic_webmail_report_error($message, array(), WATCHDOG_WARNING);
  }
}


/**
 * Checks if the standard mailboxes exist and creates them, if necessary.
 *
 * This function checks to see if the standard mailboxes exit or not. If they
 * do not exist, this function will also create them. This fucntion will then
 * subscribe to the mailboxes.
 *
 * @param integer $user_id
 *   The user ID of the mailbox to subscribe to.
 */
function _basic_webmail_subscribe_to_mailboxes($user_id) {
  // Connect to the server and retrieve a connection to the mailbox.
  include_once drupal_get_path('module', 'basic_webmail') . '/basic_webmail.common.inc';
  $imap_resource = _basic_webmail_connect_to_server($user_id);
  if (empty($imap_resource)) {
    $message = 'There was an error connecting to the mail server. Contact the system administrator and/or check the logs for more information.';
    _basic_webmail_report_error($message, array(), WATCHDOG_ERROR, TRUE);
    return;
  }

  $mailboxes = array(
    'INBOX',
    'INBOX.Drafts',
    'INBOX.Junk',
    'INBOX.Sent',
    'INBOX.Trash',
  );
  foreach ($mailboxes as $mailbox) {
    if (!imap_status($imap_resource, _basic_webmail_get_server_string() . $mailbox, SA_ALL)) {
      if (!imap_createmailbox($imap_resource, _basic_webmail_get_server_string() . $mailbox)) {
        $message = 'There was an error creating to the !mailbox mailbox.';
        $message_parameters = array('!mailbox' => $mailbox);
        _basic_webmail_report_error($message, $message_parameters, WATCHDOG_WARNING);
      }
    }

    if (!imap_subscribe($imap_resource, _basic_webmail_get_server_string() . $mailbox)) {
      $message = 'There was an error subscribing to the !mailbox mailbox.';
      $message_parameters = array('!mailbox' => $mailbox);
      _basic_webmail_report_error($message, $message_parameters, WATCHDOG_WARNING);
    }
  }

  // Clean up.
  if (!imap_close($imap_resource)) {
    $message = 'There was an error closing the IMAP stream.';
    _basic_webmail_report_error($message, array(), WATCHDOG_WARNING);
  }
}


/**
 * Processes a messasge's subject for storage in the database.
 *
 * @param string $subject
 *   The subject of the message.
 * @param integer $new_or_unread
 *   Indicates whether the message is new or unread or neither. If the message
 *   is new or unread, this is TRUE.
 * @param integer $message_number
 *   The number of the message in the mailbox.
 * @param string $folder
 *   The folder the message is in.
 *
 * @return string
 *   The subject of the message processed as a link for display and for storage
 *   in the database.
 */
function _basic_webmail_process_subject($subject, $new_or_unread, $message_number, $folder) {
  if ($subject != '(No subject specified)') {
    $subject = _basic_webmail_prepare_email_string($subject);
  }

  return $subject ;
}


/**
 * Processes the address of the messasge sender for storage in the database.
 *
 * @param object $from
 *   The sender of the message.
 *
 * @return string
 *   The address of the sender processed as a link for display and for storage
 *   in the database.
 */
function _basic_webmail_process_from_address($from) {
  $from_address = array();

  if (empty($from->mailbox) && empty($from->host)) {
    // If the sender's mailbox and host are blank set a generic from name.
    $from_address['address'] = '(Unknown)';
    $from_address['persona'] = '(Unknown)';
  }
  elseif (!empty($from->personal)) {
    $from_address['persona'] = _basic_webmail_prepare_email_string($from->personal);
    $from_address['address'] = $from->mailbox . '@' . $from->host;
  }
  else {
    $from_address['address'] = $from->mailbox . '@' . $from->host;
    $from_address['persona'] = $from_address['address'];
  }

  return $from_address;
}
