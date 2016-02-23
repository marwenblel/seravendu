<?php
/**
 * @file
 * Theme functions for Views Slideshow JCarousel
 */


function _views_slideshow_jcarousel_preprocess_views_slideshow_jcarousel_main_frame(&$vars) {
  $settings = $vars['settings'];
  $rows = $vars['rows'];
  $view = $vars['view'];
  $vss_id = $vars['vss_id'];

  $vars['classes_array'][]='jcarousel';

  $settings = array_merge(
    array(
      'num_divs' => sizeof($rows),
      'id_prefix' => '#views_slideshow_jcarousel_main_',
      'div_prefix' => '#views_slideshow_jcarousel_div_',
      'vss_id' => $vss_id,
    ),
    $settings
  );

  $slideshow_count = 1;

  if ($slideshow_count > 1) {
    $vss_id .= '-' . $slideshow_count;
    $settings['vss_id'] = $vss_id;
  }

  // Load our cycle css
  drupal_add_js(_views_slideshow_jcarousel_library_path());
  drupal_add_js(drupal_get_path('module','views_slideshow_jcarousel') . '/js/views_slideshow_jcarousel.js');
  drupal_add_css(drupal_get_path('module','views_slideshow_jcarousel') . '/css/views_slideshow_jcarousel.css');

//  // Add hover intent library
//  if ($settings['pause']) {
//    if (module_exists('libraries')) {
//      // Load jQuery hoverIntent
//      $hoverIntent_path = libraries_get_path('jquery.hoverIntent');
//      if (!empty($hoverIntent_path) && file_exists($hoverIntent_path . '/jquery.hoverIntent.js')) {
//        drupal_add_js($hoverIntent_path . '/jquery.hoverIntent.js');
//      }
//    }
//  }

  // Add the slideshow elements.
//  $vars['classes_array'][] = 'views_slideshow_cycle_teaser_section';


  // Retrive the number of items per frame
  if (isset($styles['items_per_slide']) && $styles['items_per_slide'] > 0) {
    $items_per_slide = $styles['items_per_slide'];
  }
  elseif (isset($styles_default['items_per_slide']) && $styles_default['items_per_slide'] > 0) {
    $items_per_slide = $styles_default['items_per_slide'];
  }
  else {
    $items_per_slide = 1;
  }

  $vars['items_per_slide'] = $items_per_slide;

  $items = array();
  $slideshow_count = 0;
  $rendered_rows = '';
  foreach ($rows as $count => $item) {
    $items[] = $item;
    if (count($items) == $items_per_slide || $count == (count($rows)-1)) {
      $rendered_rows .= theme(views_theme_functions('views_slideshow_jcarousel_main_frame_row', $vars['view'], $vars['view']->display[$vars['view']->current_display]), array('vss_id' => $vss_id, 'items' => $items, 'count' => $slideshow_count, 'view' => $vars['view']));
      $items = array();
      $slideshow_count++;
    }
  }

  $vars['rendered_rows'] = $rendered_rows;
}

/**
 * Views Slideshow slideshow rows.
 *
 * @ingroup themeable
 */
function _views_slideshow_jcarousel_preprocess_views_slideshow_jcarousel_main_frame_row(&$vars) {
  $current = $vars['count'] + 1;
  $vars['classes_array'][] = 'views_slideshow_jcarousel_slide';
  $vars['classes_array'][] = 'views_slideshow_slide views-row-' . $current;

  if ($vars['count']) {
    $vars['classes_array'][] =  'views_slideshow_jcarousel_hidden';
  }
  $vars['classes_array'][] = ($vars['count'] % 2) ? 'views-row-even' : 'views-row-odd';

  $vars['rendered_items'] = '';
  foreach ($vars['items'] as $item_count => $item) {
    $vars['rendered_items'] .= theme(views_theme_functions('views_slideshow_cycle_main_frame_row_item', $vars['view'], $vars['view']->display[$vars['view']->current_display]), array('item' => $item, 'item_count' => $item_count, 'count' => $vars['count'], 'view' => $vars['view'], 'length' => count($vars['view']->result)));
  }
}


/**
 * Theme pager fields
 */
function _views_slideshow_jcarousel_preprocess_pager(&$vars) {
  // Render all the fields unless there is only 1 slide and the user specified
  // to hide them when there is only one slide.
  $vars['rendered_field_items'] = '';
  if (empty($vars['settings']['hide_on_single_slide']) || count($vars['view']->result) > 1) {
    // Build our javascript settings.
    $js_vars = array(
      'viewsSlideshowJCarouselPager' => array(
        $vars['vss_id'] => array(
          $vars['location'] => array(
            'carouselObj' => '',
            'moveOnChange' => $vars['settings']['views_slideshow_jcarousel_pager_move_on_change'],
  					'updateOnPrevNext' => $vars['settings']['views_slideshow_jcarousel_pager_update_on_prev_next'],
            'orientation' => $vars['settings']['views_slideshow_jcarousel_pager_orientation'],
            'scroll' => $vars['settings']['views_slideshow_jcarousel_pager_scroll'],
            'visible' => $vars['settings']['views_slideshow_jcarousel_pager_visible'],
            'wrap' => $vars['settings']['views_slideshow_jcarousel_pager_wrap'],
            'animation' => $vars['settings']['views_slideshow_jcarousel_pager_animation'],
          ),
        ),
      ),
    );

    // Add the settings to the page.
    drupal_add_js($js_vars, array('type' => 'setting', 'scope' => JS_DEFAULT));

    // Add our class to the wrapper.
    $vars['attributes_array']['class'][] = 'views_slideshow_jcarousel_pager';
    $vars['attributes_array']['class'][] = 'jcarousel-skin-' . $vars['settings']['views_slideshow_jcarousel_pager_skin'];
    $vars['attributes_array']['id'] = 'widget_pager_' . $vars['location'] . '_' . $vars['vss_id'];

    foreach ($vars['view']->result as $count => $node) {
      $rendered_fields = '';
      foreach ($vars['settings']['views_slideshow_jcarousel']['pager_fields'] as $field => $use) {
        if ($use !== 0 && is_object($vars['view']->field[$field])) {
          $rendered_fields .= theme('views_slideshow_jcarousel_pager_field', array('view' => $vars['view'], 'field' => $field, 'count' => $count));
        }
      }
      $vars['rendered_field_items'] .= theme('views_slideshow_jcarousel_pager_item', array('vss_id' => $vars['vss_id'], 'item' => $rendered_fields, 'count' => $count, 'location' => $vars['location']));
    }
    //todo: move these includes to attachement paths in the theme handler
    if ($jcarousel_path = _views_slideshow_jcarousel_library_path()) {
      drupal_add_js($jcarousel_path);
    }

    $skins=ctools_get_plugins('views_slideshow_jcarousel','skins');
    drupal_add_css($skins[$vars['settings']['views_slideshow_jcarousel_pager_skin']]['path'] . '/skin.css');
    // Load our jcarousel pager js
    $module_path = drupal_get_path('module', 'views_slideshow_jcarousel');
    drupal_add_js($module_path . '/js/views_slideshow_jcarousel.js');
  }
}

/**
 * Views Slideshow jCarousel: pager item.
 *
 * @ingroup themeable
 */
function _views_slideshow_jcarousel_preprocess_pager_item(&$vars) {
  $current = $vars['count'] + 1;
  $classes = array(
    'views_slideshow_jcarousel_pager_item',
    'carousel-item'
  );
  if (!$vars['count']) {
    $classes[] = 'views_slideshow_active_pager_field_item';
  }
  $classes[] = ($vars['count'] % 2) ? 'views-row-even' : 'views-row-odd';

  $vars['attributes_array']['class'] = $classes;
  $vars['attributes_array']['id'] = 'views_slideshow_jcarousel_pager_item_' . $vars['location'] . '_' . $vars['vss_id'] . '_' . $vars['count'];
}

function _views_slideshow_jcarousel_preprocess_views_slideshow_pager_fields(&$vars)
{

}