<?php
class country_state_handler_filter_field_country_state extends views_handler_filter_string {
    var $form;
    var $form_state;

    function operators() {
        $operators = array(
            '=' => array(
                'title' => t('Is equal to'),
                'short' => t('='),
                'method' => 'op_equal',
                'values' => 1,
            ),
        );
        return $operators;
    }


    /**
     * Provide a simple select list for equality
     */
    function value_form(&$form, &$form_state) {

        $countries = _prepare_countries_list();
        $selected_country = isset($form_state['values']['value']['country'])?$form_state['values']['value']['country']:key($countries);
        $selected_state  =  isset($form_state['values']['value']['state'])?$form_state['values']['value']['state']:'';
        $values = array(
            'country' => array(
                '#type'          => 'select',
                '#title'         => t('Country'),
                '#options'       => $countries,
            ),
            'state' => array(
                '#type'    => 'select',
                '#title'   => t('State'),
                '#prefix'  => '<div id="dropdown-states">',
                '#suffix'  => '</div>',
                '#options' => array('All' => t('--ANY--')),
                '#validated' => TRUE
            ),
        );
        $form['value'] = $values;

        return $form;
    }


    /**
     * @param $input
     * @return bool
     */
    function accept_exposed_input($input) {

        // our identifier
        $this->options['expose']['identifier'] = array(0=> 'country', 1 => 'state');
        // parent function
        if (empty($this->options['exposed'])) {
            return TRUE;
        }


        if (!empty($this->options['expose']['use_operator']) && !empty($this->options['expose']['operator_id']) && isset($input[$this->options['expose']['operator_id']])) {
            $this->operator = $input[$this->options['expose']['operator_id']];
        }

        if (!empty($this->options['expose']['identifier'])) {
            foreach($this->options['expose']['identifier'] as $key => $id) {
             $value[$id] = $input[$this->options['expose']['identifier'][$key]];
            }
            //$value = $input[$this->options['expose']['identifier']];

            // Various ways to check for the absence of non-required input.
            if (empty($this->options['expose']['required'])) {
                if (($this->operator == 'empty' || $this->operator == 'not empty') && $value === '') {
                    $value = ' ';
                }

                if ($this->operator != 'empty' && $this->operator != 'not empty') {
                    if ( ( isset(array_count_values($value)['All']) AND array_count_values($value)['All'] == count($value) )
                        OR ( isset(array_count_values($value)['']) AND array_count_values($value)[''] == count($value) ) ) { // || $value === array()

                        return FALSE;
                    }
                }

                if (!empty($this->always_multiple) && $value === '') {
                    return FALSE;
                }
            }


            if (isset($value)) {
                $this->value = $value;
                if (empty($this->always_multiple) && empty($this->options['expose']['multiple'])) {
                    $this->value = array($value);
                }
            }
            else {
                return FALSE;
            }
        }

        return TRUE;

    }


    function op_equal($field) {


        $field_country = 'field_data_field_location.'.$this->definition['additional fields'][0];
        $field_state   = 'field_data_field_location.'.$this->definition['additional fields'][1];

        $query_config = array(
            $field_country => $this->value['country'],
            $field_state => $this->value['state'],
        );
        foreach ($query_config as $field => $value) {
            if($value != 'All') {
                $this->query->add_where($this->options['group'], $field, $value, $this->operator());
            }
        }

    }

}

/**
 * _prepare_countries_list function.
 */
function _prepare_countries_list() {
    // get all countries from location vocabulary
    $countries['All'] = t('--Any--');
    $location_vocabulary = taxonomy_vocabulary_machine_name_load('location');
    $location = taxonomy_get_tree($location_vocabulary->vid);
    foreach ($location as $item) {
        if ($item->depth == 0) {
            $countries[strtolower($item->name)] = t($item->name);
        }
    }
    return $countries;
}
/**
 * Helper function to populate the second dropdown. This would normally be
 * pulling data from the database.
 *
 * @param $key
 *   This will determine which set of options is returned.
 *
 * @return array of options
 */
function _country_state_get_second_dropdown_options($key = '') {


    // get all countries from location vocabulary
    $states = array();
    $location_vocabulary = taxonomy_vocabulary_machine_name_load('location');
    $location = taxonomy_get_tree($location_vocabulary->vid);
    foreach ($location as $item) {
        if ($item->depth == 0) {
            $childs = taxonomy_get_children($item->tid);
            $childs_array = array();
            foreach($childs as $child) {
                $childs_array[strtolower($child->name)] = t($child->name);
            }
            $states[strtolower($item->name)] = $childs_array;
        }


    }

    if (isset($states[$key])) {
        return array('All' => t('--ANY--'))+$states[$key];
    }
    else {
        return array('All' => t('--ANY--'));
    }
}