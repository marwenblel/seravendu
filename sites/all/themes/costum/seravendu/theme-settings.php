<?php
/**
 * @file
 * Theme settings for Seravendu theme.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 */
function seravendu_form_system_theme_settings_alter(&$form, &$form_state) {
    $form['seravendu_settings'] = array(
        '#type'        => 'fieldset',
        '#title'       => t('seravendu Theme Settings'),
        '#collapsible' => FALSE,
        '#collapsed'   => FALSE,
    );

    $form['seravendu_settings']['slideshow'] = array(
        '#type' => 'fieldset',
        '#title' => t('Front Page Slideshow'),
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
    );
    $form['seravendu_settings']['slideshow']['slideshow_display'] = array(
        '#type' => 'checkbox',
        '#title' => t('Show slideshow'),
        '#default_value' => theme_get_setting('slideshow_display', 'seravendu'),
        '#description'   => t("Check this option to show Slideshow in front page. Uncheck to hide."),
    );
    $form['seravendu_settings']['slideshow']['slide'] = array(
        '#markup' => t('You can change the description of each slide in the following Slide Settings.'),
    );
    $form['seravendu_settings']['slideshow']['slide1'] = array(
        '#type' => 'fieldset',
        '#title' => t('Slide 1'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
    );
    $form['seravendu_settings']['slideshow']['slide1']['slide1_title'] = array(
        '#type' => 'textfield',
        '#title' => t('Slide Title'),
        '#default_value' => theme_get_setting('slide1_title', 'seravendu'),
    );
    $form['seravendu_settings']['slideshow']['slide1']['slide1_desc'] = array(
        '#type' => 'textfield',
        '#title' => t('Slide Description'),
        '#default_value' => theme_get_setting('slide1_desc', 'seravendu'),
    );
    $form['seravendu_settings']['slideshow']['slide2'] = array(
        '#type' => 'fieldset',
        '#title' => t('Slide 2'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
    );
    $form['seravendu_settings']['slideshow']['slide2']['slide2_title'] = array(
        '#type' => 'textfield',
        '#title' => t('Slide Title'),
        '#default_value' => theme_get_setting('slide2_title', 'seravendu'),
    );
    $form['seravendu_settings']['slideshow']['slide2']['slide2_desc'] = array(
        '#type' => 'textfield',
        '#title' => t('Slide Description'),
        '#default_value' => theme_get_setting('slide2_desc', 'seravendu'),
    );
    $form['seravendu_settings']['slideshow']['slide3'] = array(
        '#type' => 'fieldset',
        '#title' => t('Slide 3'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
    );
    $form['seravendu_settings']['slideshow']['slide3']['slide3_title'] = array(
        '#type' => 'textfield',
        '#title' => t('Slide Title'),
        '#default_value' => theme_get_setting('slide3_title', 'seravendu'),
    );
    $form['seravendu_settings']['slideshow']['slide3']['slide3_desc'] = array(
        '#type' => 'textfield',
        '#title' => t('Slide Description'),
        '#default_value' => theme_get_setting('slide3_desc', 'seravendu'),
    );
    $form['seravendu_settings']['slideshow']['slideimage'] = array(
        '#markup' => t('To change the Slide Images, Replace the slide-image-1.jpg, slide-image-2.jpg and slide-image-3.jpg in the images folder of the seravendu theme folder.'),
    );
    
    
    $form['seravendu_settings']['social'] = array(
        '#type'        => 'fieldset',
        '#title'       => t('Social Icon'),
        '#collapsible' => TRUE,
        '#collapsed'   => FALSE,
    );
    $form['seravendu_settings']['social']['display'] = array(
        '#type'          => 'checkbox',
        '#title'         => t('Show Social Icon'),
        '#default_value' => theme_get_setting('display', 'seravendu'),
        '#description'   => t("Check this option to show Social Icon. Uncheck to hide."),
    );
    $form['seravendu_settings']['social']['twitter'] = array(
        '#type'          => 'textfield',
        '#title'         => t('Twitter URL'),
        '#default_value' => theme_get_setting('twitter', 'seravendu'),
        '#description'   => t("Enter your Twitter Profile URL. example:: http://www.xyz.com"),
    );
    $form['seravendu_settings']['social']['facebook'] = array(
        '#type'          => 'textfield',
        '#title'         => t('Facebook URL'),
        '#default_value' => theme_get_setting('facebook', 'seravendu'),
        '#description'   => t("Enter your Facebook Profile URL. example:: http://www.xyz.com"),
    );
    $form['seravendu_settings']['social']['linkedin'] = array(
        '#type'          => 'textfield',
        '#title'         => t('LinkedIn URL'),
        '#default_value' => theme_get_setting('linkedin', 'seravendu'),
        '#description'   => t("Enter your LinkedIn Profile URL. example:: http://www.xyz.com"),
    );

    $form['seravendu_settings']['footer'] = array(
        '#type' => 'fieldset',
        '#title' => t('Footer'),
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
    );
    $form['seravendu_settings']['footer']['footer_copyright'] = array(
        '#type' => 'checkbox',
        '#title' => t('Show copyright text in footer'),
        '#default_value' => theme_get_setting('footer_copyright', 'seravendu'),
        '#description'   => t("Check this option to show copyright text in footer. Uncheck to hide."),
    );
    $form['seravendu_settings']['footer']['footer_developed'] = array(
        '#type' => 'checkbox',
        '#title' => t('Show theme developed by in footer'),
        '#default_value' => theme_get_setting('footer_developed', 'seravendu'),
        '#description'   => t("Check this option to show design & developed by text in footer. Uncheck to hide."),
    );
    $form['seravendu_settings']['footer']['footer_developedby'] = array(
        '#type' => 'textfield',
        '#title' => t('Add name developed by in footer'),
        '#default_value' => theme_get_setting('footer_developedby', 'seravendu'),
        '#description'   => t("Add name developed by in footer"),
    );
    $form['seravendu_settings']['footer']['footer_developedby_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Add link to developed by in footer'),
        '#default_value' => theme_get_setting('footer_developedby_url', 'seravendu'),
        '#description'   => t("Add url developed by in footer. example:: http://www.xyz.com"),
    );

}