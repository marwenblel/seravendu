<?php
/**
 * @file
 * This file handles the administrative settings and configuration.
 */

/**
 * Administration settings form.
 *
 * @return array
 *   The completed form definition.
 */
function basic_webmail_admin_settings($form, &$form_state) {
  $form = array();

  // The message display set of fields for the form.
  $form['basic_webmail_viewing_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Message viewing settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['basic_webmail_viewing_settings']['basic_webmail_allowed_tags'] = array(
    '#type' => 'textfield',
    '#title' => t('Allowed tags'),
    '#maxlength' => 256,
    '#default_value' => variable_get('basic_webmail_allowed_tags', '<a> <cite> <code> <dd> <dl> <dt> <em> <li> <ol> <strong> <ul>'),
    '#description' => t('This is the list of HTML tags that are allowed to be displayed in HTML emails.'),
  );
  $form['basic_webmail_viewing_settings']['basic_webmail_attachment_location'] = array(
    '#type' => 'textfield',
    '#title' => t('Attachment location'),
    '#default_value' => variable_get('basic_webmail_attachment_location', file_default_scheme() . '://attachments'),
    '#description' => t('The file path where to save message attachments.'),
  );

  // The message display set of fields for the form.
  $form['basic_webmail_composition_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Message composition settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  // HTML and file attachment options.
  if (module_exists('mimemail')) {
    $basic_webmail_text_format = variable_get('basic_webmail_text_format');
    $form['basic_webmail_composition_settings']['basic_webmail_text_format'] = array(
      '#type' => 'text_format',
      '#title' => t('The default text format'),
      '#default_value' => t('The text of this field is not saved or used anywhere.'),
      '#format' => !empty($basic_webmail_text_format['format']) ? $basic_webmail_text_format['format'] : NULL,
      '#description' => t('This is the text format that will be initially selected. If you do not want to allow HTML messages, then specify a plain text text format and do not aloow it to be overridden below. Keep in mind that the user sending the message may not have access to all the text formats that are available here.'),
    );

    $max_file_uploads = ini_get('max_file_uploads');
    if (!empty($max_file_uploads)) {
      $description = t("The number of attachments to allow on the message composition form. The maximum number of allowed uploads may be limited by PHP. Your system's php.ini file has it set to @max_file_uploads. To change it, alter the max_file_uploads directive.", array('@max_file_uploads' => $max_file_uploads));
    }
    else {
      $description = t("The number of attachments to allow on the message composition form. The maximum number of allowed uploads may be limited by PHP. If necessary, check your system's PHP php.ini file for a max_file_uploads directive to change.");
    }
    $form['basic_webmail_composition_settings']['basic_webmail_number_attachments'] = array(
      '#type' => 'textfield',
      '#title' => t('Number of attachments'),
      '#size' => 10,
      '#default_value' => variable_get('basic_webmail_number_attachments', 3),
      '#description' => $description,
    );
  }
  else {
    $form['basic_webmail_composition_settings']['basic_webmail_attachment_notice'] = array(
      '#type' => 'item',
      '#description' => t('This module no longer supports composing HTML messages or attaching files without the Mime Mail module, which can be found here: http://drupal.org/project/mimemail.'),
    );
  }

  // The user set of fields for the form.
  $form['basic_webmail_user_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('User settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $disabled = TRUE;
  if (module_exists('aes') || module_exists('encrypt')) {
    $disabled = FALSE;
  }
  $form['basic_webmail_user_settings']['basic_webmail_use_encryption'] = array(
    '#type' => 'checkbox',
    '#title' => t("Use encryption when saving the user's password."),
    '#disabled' => $disabled,
    '#default_value' => variable_get('basic_webmail_use_encryption', 0),
    '#description' => t("By default, the login information is saved in clear text in the data field of the user table. Check this box to enable encrypting the passwords before saving them. This option requires either the !aes or !encrypt modules.",
      array(
        '!aes' => l('AES encryption', 'http://drupal.org/project/aes'),
        '!encrypt' => l('Encryption', 'http://drupal.org/project/encrypt')
      )
    ),
  );

  // The server set of fields for the form.
  $form['basic_webmail_server_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Mail server settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['basic_webmail_server_settings']['basic_webmail_server_address'] = array(
    '#type' => 'textfield',
    '#title' => t('Server address'),
    '#default_value' => variable_get('basic_webmail_server_address', ''),
    '#description' => t('The address to the server you wish to connect to.'),
  );
  $form['basic_webmail_server_settings']['basic_webmail_server_port'] = array(
    '#type' => 'textfield',
    '#title' => t('Connection port'),
    '#size' => 10,
    '#default_value' => variable_get('basic_webmail_server_port', 143),
    '#description' => t('The default IMAP port is 143, if one is not specified. If you are using SSL, the default port number is 993. If you are using TLS, the default port number is 143.'),
  );
  $form['basic_webmail_server_settings']['basic_webmail_secure_log_in'] = array(
    '#type' => 'checkbox',
    '#title' => t('Secure login'),
    '#default_value' => variable_get('basic_webmail_secure_log_in', 0),
    '#description' => t('Check to make a secure connection to your IMAP Server.'),
  );
  $form['basic_webmail_server_settings']['basic_webmail_use_ssl'] = array(
    '#type' => 'checkbox',
    '#title' => t('Encrypt session using SSL'),
    '#default_value' => variable_get('basic_webmail_use_ssl', 0),
    '#description' => t('Use SSL to connect to the server.'),
  );
  $form['basic_webmail_server_settings']['basic_webmail_validate_cert'] = array(
    '#type' => 'checkbox',
    '#title' => t('Validate certificate'),
    '#default_value' => variable_get('basic_webmail_validate_cert', 0),
    '#description' => t('When using a secure connection, validate the certificate.'),
  );
  $form['basic_webmail_server_settings']['basic_webmail_use_tls'] = array(
    '#type' => 'checkbox',
    '#title' => t('Encrypt session using TLS'),
    '#default_value' => variable_get('basic_webmail_use_tls', 0),
    '#description' => t('Use TLS to connect to the server.'),
  );

  return system_settings_form($form);
}

/**
 * Additional vaidation for the administration settings form.
 *
 * @param array $form
 *   The form definition.
 * @param array $form_state
 *   The form values of the passed form.
 */
function basic_webmail_admin_settings_validate($form, &$form_state) {
  if (!file_prepare_directory($form_state['values']['basic_webmail_attachment_location'], FILE_CREATE_DIRECTORY)) {
    form_set_error('basic_webmail_attachment_location', t('The directory does not exist or is not writable, and there was a problem creating the path.'));
  }

  if ($form_state['values']['basic_webmail_use_ssl'] == 1 && $form_state['values']['basic_webmail_server_port'] == '143') {
    form_set_error('basic_webmail_server_port', t('The normal port for secure IMAP is 993.'));
  }
}
