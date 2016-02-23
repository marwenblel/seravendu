<?php
/**
 * @file
 * Default views template for displaying a slideshow.
 *
 * - $view: The View object.
 * - $options: Settings for the active style.
 * - $rows: The rows output from the View.
 * - $title: The title of this group of rows. May be empty.
 *
 * @ingroup views_templates
 */
?>

<?php if (!empty($slideshow)): ?>
  <div class="wrapper jcarousel-skin-<?php print $skin; ?>">
    <!--todo: need to make this conditional based on whether the carousel has a pager or not -->
    <div class="connected-carousels">

      <?php if (!empty($top_widget_rendered)): ?>
        <div class="views-slideshow-controls-top clearfix">
          <?php print $top_widget_rendered; ?>
        </div>
      <?php endif; ?>

      <?php print $slideshow; ?>

      <?php if (!empty($bottom_widget_rendered)): ?>
        <div class="views-slideshow-controls-bottom clearfix">
          <?php print $bottom_widget_rendered; ?>
        </div>
      <?php endif; ?>
    </div>
  </div>

<?php endif; ?>
