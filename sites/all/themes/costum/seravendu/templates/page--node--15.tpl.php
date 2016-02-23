<?php
/**
 * @file
 */
?>
<!-- page-wrapper starts -->
<div id="page-wrapper">
    <!-- #page starts -->
    <div id="page">

        <!-- #socialbar Starts -->
        <?php if ($display): ?>
            <div id="socialbar">
                <ul class="social">
                    <?php $options['attributes'] = array('target' => '_blank'); ?>
                    <?php if ($facebook): ?><li class="fb"><?php print l(t('facebook'), $facebook, $options); ?></li> <?php endif; ?>
                    <?php if ($twitter): ?><li class="tw"><?php print l(t('twitter'), $twitter, $options); ?></li> <?php endif; ?>
                    <?php if ($linkedin): ?><li class="ln"><?php print l(t('linkedin'), $linkedin, $options); ?></li> <?php endif; ?>
                </ul>
            </div>
        <?php endif; ?>
        <!-- #socialbar Ends -->

        <!-- #header starts -->
        <div id="header" class="clearfix">
            <div class="row">

                <?php if ($logo || $site_slogan): ?>
                    <div id="logo_slogan_wrapper" class="col-md-4">
                        <!-- #logo START -->
                        <?php if ($logo): ?>
                            <div id="logo">
                                <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a>
                            </div>
                        <?php endif; ?>
                        <!-- #logo Ends -->

                        <!-- #site slogan Starts -->
                        <?php if ($site_slogan): ?>
                            <div id="sitename">
                                <p><?php print $site_slogan; ?></p><!--site slogan-->
                            </div>
                        <?php endif; ?>
                        <!-- #site slogan Ends -->
                    </div>
                <?php endif; ?>


                <!-- #navigation STARTs -->
                <div id="navigation" class="clearfix col-md-9">
                    <div id="main-menu">
                        <?php print theme('links__system_main_menu', array('links' => $main_menu, 'attributes' => array('class' => array('menu')),)); ?>
                    </div>
                </div>
                <!-- #navigation Ends -->



            </div>





            <div class="row">

                <div class="col-md-9">
                    <?php print render($page['header']); ?>
                </div>


                <!-- #customers-phone STARTs -->
                <div id="customers-phone" class="col-md-3">
                    <table>
                        <tr>
                            <td><label class="title"><?php print(t('Customers service'));?></php></label></td>
                            <td><span class="glyphicon glyphicon-info-sign" aria-hidden="true"></span></td>
                        </tr>
                        <tr>
                            <td><label class="phone"><?php print($site_customer_phone);?></label></td>
                            <td><span class="glyphicon glyphicon-phone-alt" aria-hidden="true"></span></td>
                        </tr>
                    </table>
                </div>
                <!-- #customers-phone ends -->

            </div>


        </div>
        <!-- #header ends -->



        <!-- Slider Starts -->
        <?php if ($slideshow_display): ?>
            <div id="slider">
                <div id ="slide" class="main_view">
                    <div class="slide-area">
                        <div id="divider_wrapper"><div id="divider"></div></div>
                        <div class="slide_image">
                            <?php print $slideimage1; ?>
                            <?php print $slideimage2; ?>
                            <?php print $slideimage3; ?>
                        </div>

                        <?php if ($slide1_title || $slide1_desc):?>
                            <div class="descriptions" style="display: none;">
                                <div class="desc" >
                                    <div class="desc_top" ><?php print $slide1_title; ?></div>
                                    <div class="desc_bottom" ><?php print $slide1_desc; ?></div>
                                </div>
                            </div>
                        <?php endif; ?>
                        <?php if ($slide2_title || $slide2_desc):?>
                            <div class="descriptions" style="display: none;">
                                <div class="desc" >
                                    <div class="desc_top"><?php print $slide2_title; ?></div>
                                    <div class="desc_bottom"><?php print $slide2_desc; ?></div>
                                </div>
                            </div>
                        <?php endif; ?>
                        <?php if ($slide3_title || $slide3_desc):?>
                            <div class="descriptions" style="display: none;">
                                <div class="desc">
                                    <div class="desc_top"><?php print $slide3_title; ?></div>
                                    <div class="desc_bottom"><?php print $slide3_desc; ?></div>
                                </div>
                            </div>
                        <?php endif; ?>
                    </div>
                    <div class="paging">
                        <a rel="1" href="#"></a>
                        <a rel="2" href="#"></a>
                        <a rel="3" href="#"></a>
                    </div>
                </div>
            </div>
        <?php endif; ?>
        <!-- Slider Ends -->





        <?php print $messages; ?>

        <!-- #beadcrumb starts-->
        <?php if ($breadcrumb): ?>
            <div id="breadcrumb"><?php print $breadcrumb; ?></div>
        <?php endif; ?>
        <!-- #beadcrumb ends-->

        <div id="main-wrapper"><div id="main" class="clearfix">

                <div id="content" class="column"><div class="section">
                        <?php if ($page['highlighted']): ?><div id="highlighted"><?php print render($page['highlighted']); ?></div><?php endif; ?>
                        <a id="main-content"></a>
                        <?php print render($title_prefix); ?>
                        <?php if ($title): ?><h1 class="title" id="page-title"><?php print $title; ?></h1><?php endif; ?>
                        <?php print render($title_suffix); ?>
                        <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
                        <?php print render($page['help']); ?>
                        <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
                        <?php print render($page['content']); ?>
                        <?php print $feed_icons; ?>
                    </div></div> <!-- /.section, /#content -->

                <?php if ($page['sidebar_first']): ?>
                    <div id="sidebar-first" class="column sidebar"><div class="section">
                            <?php print render($page['sidebar_first']); ?>
                        </div></div> <!-- /.section, /#sidebar-first -->
                <?php endif; ?>

                <?php if ($page['sidebar_second']): ?>
                    <div id="sidebar-second" class="column sidebar"><div class="section">
                            <?php print render($page['sidebar_second']); ?>
                        </div></div> <!-- /.section, /#sidebar-second -->
                <?php endif; ?>

            </div></div> <!-- /#main, /#main-wrapper -->





        <!--Footer context Start -->
        <div id="footer-context">
            <!--Footer Start -->
            <div id="footer-bottom">
                <?php print render($page['footer']) ?>
                <?php if ($footer_copyright || $footer_developed): ?>
                    <div id="copyright">
                        <?php if ($footer_copyright): ?>
                            <?php print t('Copyright'); ?> &copy; <?php print date("Y"); ?>, <?php print $site_name; ?>.
                        <?php endif; ?>
                        <?php if ($footer_developed): ?>
                            <span class="developed"><?php print t('Designed & Develop by'); ?>
                                <a href="<?php print ($footer_developedby_url); ?> " target="_blank">
                                    <?php print ($footer_developedby); ?>
                                </a>
          </span>
                        <?php endif; ?>
                    </div>
                <?php endif; ?>
            </div>
            <!--Footer Ends -->
        </div>
        <!--Footer context Ends -->




    </div>
    <!-- #page ends -->
</div>
<!-- #page-wrapper ends -->
