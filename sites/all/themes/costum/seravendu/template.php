<?php
/**
 * Add javascript files for front-page jquery slideshow.
 */
$current_nid = current_path();
if ($current_nid == 'node/15') {
    drupal_add_js(drupal_get_path('theme', 'seravendu') . '/js/slider.js');

}

/**
 * Implements hook_preprocess_page().
 */
function seravendu_preprocess_page (&$vars) {
    $vars['display']  = theme_get_setting('display', 'seravendu');
    $vars['twitter']  = theme_get_setting('twitter', 'seravendu');
    $vars['facebook'] = theme_get_setting('facebook', 'seravendu');
    $vars['linkedin'] = theme_get_setting('linkedin', 'seravendu');
    // Frontpage variables.
    $vars['slideshow_display'] = theme_get_setting('slideshow_display', 'seravendu');
    $vars['slide1_title']      = theme_get_setting('slide1_title', 'seravendu');
    $vars['slide2_title']      = theme_get_setting('slide2_title', 'seravendu');
    $vars['slide3_title']      = theme_get_setting('slide3_title', 'seravendu');
    $vars['slide1_desc']       = theme_get_setting('slide1_desc', 'seravendu');
    $vars['slide2_desc']       = theme_get_setting('slide2_desc', 'seravendu');
    $vars['slide3_desc']       = theme_get_setting('slide3_desc', 'seravendu');
    $vars['img1']              = base_path() . drupal_get_path('theme', 'seravendu') . '/images/slideshow/slide-image-1.jpg';
    $vars['img2']              = base_path() . drupal_get_path('theme', 'seravendu') . '/images/slideshow/slide-image-2.jpg';
    $vars['img3']              = base_path() . drupal_get_path('theme', 'seravendu') . '/images/slideshow/slide-image-3.jpg';
    $image1var = array(
        'path' => $vars['img1'],
        'alt' => $vars['slide1_title'],
        'title' => $vars['slide1_title'],
        'attributes' => array('class' => 'slide-img'),
    );
    $vars['slideimage1'] = theme('image', $image1var);
    $image2var = array(
        'path' => $vars['img2'],
        'alt' => $vars['slide2_title'],
        'title' => $vars['slide2_title'],
        'attributes' => array('class' => 'slide-img'),
    );
    $vars['slideimage2'] = theme('image', $image2var);
    $image3var = array(
        'path' => $vars['img3'],
        'alt' => $vars['slide3_title'],
        'title' => $vars['slide3_title'],
        'attributes' => array('class' => 'slide-img'),
    );
    $vars['slideimage3'] = theme('image', $image3var);

    $vars['footer_copyright'] = theme_get_setting('footer_copyright');
    $vars['footer_developed'] = theme_get_setting('footer_developed');
    $vars['footer_developedby_url'] = filter_xss_admin(theme_get_setting('footer_developedby_url', 'seravendu'));
    $vars['footer_developedby'] = filter_xss_admin(theme_get_setting('footer_developedby', 'seravendu'));

    // customers phone site.
    $vars['site_customer_phone'] = variable_get('site_customer_phone', 0);

}
/**
 * Implements hook_block_view_alter
 */

/*function seravendu_block_view_alter(&$data, $block) {

   switch ($block->delta) {
       case 'login':
           $data['subject'] = '';
           break;
       case 'customer_info_widget':
           $data['subject'] = '';
           break;

       case 'main-menu':
           $data['subject'] = '';
           break;
       case 'featured_cars-block':
           $data['subject'] = '';
           break;
       case 'tabbed_car_ads_list':
           $data['subject'] = '';
           break;
       case 'user-menu':
           $data['subject'] = '';
           break;
   }
}*/
/**
 * Implements hook_preprocess_region().
 */
/*function seravendu_preprocess_region(&$variables, $hook) {
    if($variables['region'] == 'header'){
        $variables['classes_array'][] = 'row';
    }
}*/
/**
 * Implements hook_preprocess_block().
 */
/*function seravendu_preprocess_block(&$vars) {
    // Set shortcut variables
    $block_id = $vars['block']->module . '-' . $vars['block']->delta;
    $region   = $vars['block']->region;
    $block_region = $block_id.'+'.$region;
    $classes = &$vars['classes_array'];


    // Add classes based on the block delta
    switch ($block_region) {
        case 'logo_block-logo+header':
            $classes[] = 'col-md-4';
            break;
        case 'customer_widgets-customer_info_widget+header':
            $classes[] = 'col-md-4';
            $classes[] = 'alert';
            break;
        case 'user-login+header':
            $classes[] = 'col-md-4';
            break;
        case 'system-main-menu+navigation':
            $classes[] = 'col-md-8';
            break;
        case 'system-user-menu+navigation':
            $classes[] = 'col-md-4';
            break;
        case 'views--exp-search_cars-page+highlighted':
            $classes[] = 'well';
            break;

    }
}*/
