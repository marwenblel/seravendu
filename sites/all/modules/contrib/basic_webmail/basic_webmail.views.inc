<?php

/**
 * Implements hook_views_data().
 */
function basic_webmail_views_data() {
  $data = array();

  // The messages.
  // Define the base group of this table. Fields that don't have a group defined
  // will go into this field by default.
  $data['basic_webmail_messages']['table']['group'] = t('Basic webmail messages');

  // Advertize this table as a possible base table
  $data['basic_webmail_messages']['table']['base'] = array(
    'title' => t('Basic webmail messages'),
    'help' => t('Email messages temporarily stored in the database.'),
  );

  // The fields of the table.
  $data['basic_webmail_messages']['user_id'] = array(
    'title' => t('User ID'),
    'help' => t('The user to whom this message belongs.'),
    // Information for displaying the field.
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    // Information for accepting this field as a filter.
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    // Information for sorting on this field.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    // Information for accepting this field as an argument.
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['basic_webmail_messages']['message_number'] = array(
    'title' => t('Message number'),
    'help' => t('The message ID on the server.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['basic_webmail_messages']['message_subject'] = array(
    'title' => t('Message subject'),
    'help' => t('The subject of the message.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['basic_webmail_messages']['from_address'] = array(
    'title' => t('From address'),
    'help' => t('Who the message is from.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['basic_webmail_messages']['from_persona'] = array(
    'title' => t('From persona'),
    'help' => t('The displayed name of who the message is from.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['basic_webmail_messages']['message_date'] = array(
    'title' => t('Message date'),
    'help' => t('The date and time the message was sent.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );
  $data['basic_webmail_messages']['message_unread'] = array(
    'title' => t('Unread'),
    'help' => t('Indicates if the message is read or unread.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['basic_webmail_messages']['attachment_exists'] = array(
    'title' => t('Attachment(s)'),
    'help' => t('Indicates if there are any attachments or not.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['basic_webmail_messages']['message_answered'] = array(
    'title' => t('Answered'),
    'help' => t('Indicates if the message was replied to or not.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['basic_webmail_messages']['folder_name'] = array(
    'title' => t('Folder name'),
    'help' => t('The folder the message is in.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // The folders.
  // Define the base group of this table. Fields that don't have a group defined
  // will go into this group by default.
  $data['basic_webmail_folders']['table']['group'] = t('Basic webmail folders');

  // Advertise this table as a possible base table
  $data['basic_webmail_folders']['table']['base'] = array(
    'title' => t('Basic webmail folders'),
    'help' => t('Email folders stored in the database.'),
  );

  // The fields of the table.
  $data['basic_webmail_folders']['user_id'] = array(
    'title' => t('User ID'),
    'help' => t('The user to whom this folder belongs.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['basic_webmail_folders']['folder_name'] = array(
    'title' => t('Folder name'),
    'help' => t('The name of the folder.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  return $data;
}
