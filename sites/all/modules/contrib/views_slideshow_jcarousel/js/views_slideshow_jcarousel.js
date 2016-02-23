/**
 * Views Slideshow jCarousel Pager
 */

// Add views slideshow api calls for views slideshow jCarousel.
Drupal.behaviors.viewsSlideshowJcarousel = {
  attach: function (context) {
      // This is the connector function.
      // It connects one item from the navigation carousel to one item from the
      // stage carousel.
      // The default behaviour is, to connect items with the same index from both
      // carousels. This might _not_ work with circular carousels!
      var connector = function(itemNavigation, carouselStage) {
          return carouselStage.jcarousel('items').eq(itemNavigation.index());
      };

      jQuery(function() {
          // Setup the carousels. Adjust the options for both carousels here.
          jQuery('.connected-carousels').each(function() {
              var carouselStage = jQuery('.carousel-stage', this).jcarousel();
              var carouselNavigation = jQuery('.carousel-navigation',this).jcarousel();
              carouselStage.jcarousel('items').width(carouselStage.width());
              carouselNavigation.jcarousel('items').width(carouselNavigation.width() / 2);
              carouselNavigation.jcarousel('items').height(carouselNavigation.height());
              //carouselNavigation.jcarousel('items').width('100px');

              // We loop through the items of the navigation carousel and set it up
              // as a control for an item from the stage carousel.
              carouselNavigation.jcarousel('items').each(function () {
                  var item = jQuery(this);

                  // This is where we actually connect to items.
                  var target = connector(item, carouselStage);

                  item
                      .on('jcarouselcontrol:active', function () {
                          carouselNavigation.jcarousel('scrollIntoView', this);
                          item.addClass('active');
                      })
                      .on('jcarouselcontrol:inactive', function () {
                          item.removeClass('active');
                      })
                      .jcarouselControl({
                          target: target,
                          carousel: carouselStage
                      });
              });

              // Setup controls for the stage carousel
              jQuery('.prev-stage', this)
                  .on('jcarouselcontrol:inactive', function () {
                      jQuery(this).addClass('inactive');
                  })
                  .on('jcarouselcontrol:active', function () {
                      jQuery(this).removeClass('inactive');
                  })
                  .jcarouselControl({
                      target: '-=1'
                  });

              jQuery('.next-stage', this)
                  .on('jcarouselcontrol:inactive', function () {
                      jQuery(this).addClass('inactive');
                  })
                  .on('jcarouselcontrol:active', function () {
                      jQuery(this).removeClass('inactive');
                  })
                  .jcarouselControl({
                      target: '+=1'
                  });

              // Setup controls for the navigation carousel
              jQuery('.prev-navigation', this)
                  .on('jcarouselcontrol:inactive', function () {
                      jQuery(this).addClass('inactive');
                  })
                  .on('jcarouselcontrol:active', function () {
                      jQuery(this).removeClass('inactive');
                  })
                  .jcarouselControl({
                      target: '-=1'
                  });

              jQuery('.next-navigation', this)
                  .on('jcarouselcontrol:inactive', function () {
                      jQuery(this).addClass('inactive');
                  })
                  .on('jcarouselcontrol:active', function () {
                      jQuery(this).removeClass('inactive');
                  })
                  .jcarouselControl({
                      target: '+=1'
                  });
          });
      });
  }
};


