<?php
/**
 * @file
 * country_state.views.inc
 */

/**
 * Implements hook_views_data_alter().
 */
function country_state_views_data_alter (&$data) {
    // Get field name
   $field_name = variable_get('field_name', '');



    $data['field_data_'.$field_name]['field_data_'.$field_name.'_new'] = $data['field_data_'.$field_name][$field_name.'_country'];
    $data['field_data_'.$field_name]['field_data_'.$field_name.'_new']['title']             = t('Location new filter');
    $data['field_data_'.$field_name]['field_data_'.$field_name.'_new']['help']              = t('Location new filter');
    $data['field_data_'.$field_name]['field_data_'.$field_name.'_new']['filter']['handler'] = 'country_state_handler_filter_field_country_state';


}