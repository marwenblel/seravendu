<?php

/**
 * Implements hook_views_default_views().
 */
function basic_webmail_views_default_views() {
  $views = array();

  $view = new view();
  $view->name = 'basic_webmail';
  $view->description = 'Your email, displayed in a listing on this website.';
  $view->tag = 'default';
  $view->base_table = 'basic_webmail_messages';
  $view->human_name = 'Basic webmail';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Basic webmail';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access basic_webmail';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'user_id' => 'user_id',
    'message_number' => 'message_number',
    'message_subject' => 'message_subject',
    'from_address' => 'from_address',
    'message_date' => 'message_date',
    'message_unread' => 'message_unread',
    'attachment_exists' => 'attachment_exists',
    'message_answered' => 'message_answered',
  );
  $handler->display->display_options['style_options']['default'] = 'message_date';
  $handler->display->display_options['style_options']['info'] = array(
    'user_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'message_number' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'message_subject' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'from_address' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'message_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'message_unread' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'attachment_exists' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'message_answered' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Field: Bulk operations: Basic webmail messages */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'basic_webmail_messages';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::basic_webmail_copy_messages_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::basic_webmail_delete_messages_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::basic_webmail_mark_messages_read_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::basic_webmail_mark_messages_unread_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::basic_webmail_move_messages_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::auto_entitylabel_entity_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Basic webmail messages: User ID */
  $handler->display->display_options['fields']['user_id']['id'] = 'user_id';
  $handler->display->display_options['fields']['user_id']['table'] = 'basic_webmail_messages';
  $handler->display->display_options['fields']['user_id']['field'] = 'user_id';
  $handler->display->display_options['fields']['user_id']['exclude'] = TRUE;
  /* Field: Basic webmail messages: Message number */
  $handler->display->display_options['fields']['message_number']['id'] = 'message_number';
  $handler->display->display_options['fields']['message_number']['table'] = 'basic_webmail_messages';
  $handler->display->display_options['fields']['message_number']['field'] = 'message_number';
  $handler->display->display_options['fields']['message_number']['exclude'] = TRUE;
  /* Field: Basic webmail messages: Unread */
  $handler->display->display_options['fields']['message_unread']['id'] = 'message_unread';
  $handler->display->display_options['fields']['message_unread']['table'] = 'basic_webmail_messages';
  $handler->display->display_options['fields']['message_unread']['field'] = 'message_unread';
  $handler->display->display_options['fields']['message_unread']['type'] = 'custom';
  $handler->display->display_options['fields']['message_unread']['type_custom_true'] = 'Yes';
  $handler->display->display_options['fields']['message_unread']['not'] = 0;
  /* Field: Basic webmail messages: Answered */
  $handler->display->display_options['fields']['message_answered']['id'] = 'message_answered';
  $handler->display->display_options['fields']['message_answered']['table'] = 'basic_webmail_messages';
  $handler->display->display_options['fields']['message_answered']['field'] = 'message_answered';
  $handler->display->display_options['fields']['message_answered']['type'] = 'custom';
  $handler->display->display_options['fields']['message_answered']['type_custom_true'] = 'Yes';
  $handler->display->display_options['fields']['message_answered']['not'] = 0;
  /* Field: Basic webmail messages: Attachment(s) */
  $handler->display->display_options['fields']['attachment_exists']['id'] = 'attachment_exists';
  $handler->display->display_options['fields']['attachment_exists']['table'] = 'basic_webmail_messages';
  $handler->display->display_options['fields']['attachment_exists']['field'] = 'attachment_exists';
  $handler->display->display_options['fields']['attachment_exists']['type'] = 'custom';
  $handler->display->display_options['fields']['attachment_exists']['type_custom_true'] = 'Yes';
  $handler->display->display_options['fields']['attachment_exists']['not'] = 0;
  /* Field: Basic webmail messages: Message subject */
  $handler->display->display_options['fields']['message_subject']['id'] = 'message_subject';
  $handler->display->display_options['fields']['message_subject']['table'] = 'basic_webmail_messages';
  $handler->display->display_options['fields']['message_subject']['field'] = 'message_subject';
  $handler->display->display_options['fields']['message_subject']['label'] = 'Subject';
  $handler->display->display_options['fields']['message_subject']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['message_subject']['alter']['path'] = 'basic_webmail/view/INBOX/[message_number]';
  $handler->display->display_options['fields']['message_subject']['alter']['max_length'] = '40';
  $handler->display->display_options['fields']['message_subject']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['message_subject']['empty'] = '(no subject)';
  $handler->display->display_options['fields']['message_subject']['hide_alter_empty'] = FALSE;
  /* Field: Basic webmail messages: From address */
  $handler->display->display_options['fields']['from_address']['id'] = 'from_address';
  $handler->display->display_options['fields']['from_address']['table'] = 'basic_webmail_messages';
  $handler->display->display_options['fields']['from_address']['field'] = 'from_address';
  $handler->display->display_options['fields']['from_address']['label'] = 'From';
  $handler->display->display_options['fields']['from_address']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['from_address']['alter']['path'] = 'basic_webmail/sendmail/[from_address]';
  $handler->display->display_options['fields']['from_address']['alter']['max_length'] = '25';
  /* Field: Basic webmail messages: Message date */
  $handler->display->display_options['fields']['message_date']['id'] = 'message_date';
  $handler->display->display_options['fields']['message_date']['table'] = 'basic_webmail_messages';
  $handler->display->display_options['fields']['message_date']['field'] = 'message_date';
  $handler->display->display_options['fields']['message_date']['label'] = 'Date';
  $handler->display->display_options['fields']['message_date']['date_format'] = 'short';
  /* Contextual filter: Basic webmail messages: User ID */
  $handler->display->display_options['arguments']['user_id']['id'] = 'user_id';
  $handler->display->display_options['arguments']['user_id']['table'] = 'basic_webmail_messages';
  $handler->display->display_options['arguments']['user_id']['field'] = 'user_id';
  $handler->display->display_options['arguments']['user_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['user_id']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['user_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['user_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['user_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Basic webmail messages: Message subject */
  $handler->display->display_options['filters']['message_subject']['id'] = 'message_subject';
  $handler->display->display_options['filters']['message_subject']['table'] = 'basic_webmail_messages';
  $handler->display->display_options['filters']['message_subject']['field'] = 'message_subject';
  $handler->display->display_options['filters']['message_subject']['operator'] = 'contains';
  $handler->display->display_options['filters']['message_subject']['group'] = 1;
  $handler->display->display_options['filters']['message_subject']['exposed'] = TRUE;
  $handler->display->display_options['filters']['message_subject']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['message_subject']['expose']['label'] = 'Subject';
  $handler->display->display_options['filters']['message_subject']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['message_subject']['expose']['operator'] = 'message_subject_op';
  $handler->display->display_options['filters']['message_subject']['expose']['identifier'] = 'message_subject';
  $handler->display->display_options['filters']['message_subject']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Basic webmail messages: From address */
  $handler->display->display_options['filters']['from_address']['id'] = 'from_address';
  $handler->display->display_options['filters']['from_address']['table'] = 'basic_webmail_messages';
  $handler->display->display_options['filters']['from_address']['field'] = 'from_address';
  $handler->display->display_options['filters']['from_address']['operator'] = 'contains';
  $handler->display->display_options['filters']['from_address']['group'] = 1;
  $handler->display->display_options['filters']['from_address']['exposed'] = TRUE;
  $handler->display->display_options['filters']['from_address']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['from_address']['expose']['label'] = 'From';
  $handler->display->display_options['filters']['from_address']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['from_address']['expose']['operator'] = 'from_address_op';
  $handler->display->display_options['filters']['from_address']['expose']['identifier'] = 'from_address';
  $handler->display->display_options['filters']['from_address']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Basic webmail messages: Message date */
  $handler->display->display_options['filters']['message_date']['id'] = 'message_date';
  $handler->display->display_options['filters']['message_date']['table'] = 'basic_webmail_messages';
  $handler->display->display_options['filters']['message_date']['field'] = 'message_date';
  $handler->display->display_options['filters']['message_date']['group'] = 1;
  $handler->display->display_options['filters']['message_date']['exposed'] = TRUE;
  $handler->display->display_options['filters']['message_date']['expose']['operator_id'] = 'message_date_op';
  $handler->display->display_options['filters']['message_date']['expose']['label'] = 'Date';
  $handler->display->display_options['filters']['message_date']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['message_date']['expose']['operator'] = 'message_date_op';
  $handler->display->display_options['filters']['message_date']['expose']['identifier'] = 'message_date';
  $handler->display->display_options['filters']['message_date']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Basic webmail messages: User ID */
  $handler->display->display_options['arguments']['user_id']['id'] = 'user_id';
  $handler->display->display_options['arguments']['user_id']['table'] = 'basic_webmail_messages';
  $handler->display->display_options['arguments']['user_id']['field'] = 'user_id';
  $handler->display->display_options['arguments']['user_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['user_id']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['user_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['user_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['user_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'basic-webmail';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Basic webmail';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Most recent unread email';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'message_subject' => 'message_subject',
    'from_address' => 'from_address',
    'message_date' => 'message_date',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Basic webmail messages: User ID */
  $handler->display->display_options['fields']['user_id']['id'] = 'user_id';
  $handler->display->display_options['fields']['user_id']['table'] = 'basic_webmail_messages';
  $handler->display->display_options['fields']['user_id']['field'] = 'user_id';
  $handler->display->display_options['fields']['user_id']['exclude'] = TRUE;
  /* Field: Basic webmail messages: Message number */
  $handler->display->display_options['fields']['message_number']['id'] = 'message_number';
  $handler->display->display_options['fields']['message_number']['table'] = 'basic_webmail_messages';
  $handler->display->display_options['fields']['message_number']['field'] = 'message_number';
  $handler->display->display_options['fields']['message_number']['exclude'] = TRUE;
  /* Field: Basic webmail messages: Message subject */
  $handler->display->display_options['fields']['message_subject']['id'] = 'message_subject';
  $handler->display->display_options['fields']['message_subject']['table'] = 'basic_webmail_messages';
  $handler->display->display_options['fields']['message_subject']['field'] = 'message_subject';
  $handler->display->display_options['fields']['message_subject']['label'] = 'Subject';
  $handler->display->display_options['fields']['message_subject']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['message_subject']['alter']['path'] = 'basic_webmail/view/INBOX/[message_number]';
  $handler->display->display_options['fields']['message_subject']['alter']['max_length'] = '40';
  $handler->display->display_options['fields']['message_subject']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['message_subject']['empty'] = '(no subject)';
  $handler->display->display_options['fields']['message_subject']['hide_alter_empty'] = FALSE;
  /* Field: Basic webmail messages: From address */
  $handler->display->display_options['fields']['from_address']['id'] = 'from_address';
  $handler->display->display_options['fields']['from_address']['table'] = 'basic_webmail_messages';
  $handler->display->display_options['fields']['from_address']['field'] = 'from_address';
  $handler->display->display_options['fields']['from_address']['label'] = 'From';
  $handler->display->display_options['fields']['from_address']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['from_address']['alter']['path'] = 'basic_webmail/sendmail/[from_address]';
  $handler->display->display_options['fields']['from_address']['alter']['max_length'] = '25';
  /* Field: Basic webmail messages: Message date */
  $handler->display->display_options['fields']['message_date']['id'] = 'message_date';
  $handler->display->display_options['fields']['message_date']['table'] = 'basic_webmail_messages';
  $handler->display->display_options['fields']['message_date']['field'] = 'message_date';
  $handler->display->display_options['fields']['message_date']['label'] = 'Date';
  $handler->display->display_options['fields']['message_date']['date_format'] = 'short';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Basic webmail messages: Message date */
  $handler->display->display_options['sorts']['message_date']['id'] = 'message_date';
  $handler->display->display_options['sorts']['message_date']['table'] = 'basic_webmail_messages';
  $handler->display->display_options['sorts']['message_date']['field'] = 'message_date';
  $handler->display->display_options['sorts']['message_date']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Basic webmail messages: Unread */
  $handler->display->display_options['filters']['message_unread']['id'] = 'message_unread';
  $handler->display->display_options['filters']['message_unread']['table'] = 'basic_webmail_messages';
  $handler->display->display_options['filters']['message_unread']['field'] = 'message_unread';
  $handler->display->display_options['filters']['message_unread']['value'] = '1';

  $views[$view->name] = $view;

  return $views;
}
