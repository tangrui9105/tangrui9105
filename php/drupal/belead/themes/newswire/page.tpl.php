<?php // $Id: page.tpl.php,v 1.9 2008/10/23 13:19:01 jmburnz Exp $ 
/**
 * @file page.tpl.php
 *
 * Theme implementation to display a single Drupal page.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 */
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="<?php print $language->language; ?>" xml:lang="<?php print $language->language; ?>">
<head>
  <script type="text/javascript" src="<?php print $base_path . $directory; ?>/js/homefav.js"></script>
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <?php print $styles; ?>
  <!--[if IE]>
    <link rel="stylesheet" href="<?php print $base_path . $directory; ?>/ie.css" type="text/css">
  <![endif]-->
  <?php if (!empty($suckerfish)): ?>
  <!--[if lte IE 6]>
    <script type="text/javascript" src="<?php print $base_path . $directory; ?>/js/suckerfish.js"></script>
  <![endif]-->
   <?php endif; ?>
  <?php print $scripts; ?>
</head>
<body class="<?php print newswire_column_count_class($left, $content, $right, $right_2) . $body_class; ?>">
  <div id="container">
		
    <!-- SKIP NAV -->
				<div id="accessiblity" class="width-48-950 last nofloat">
						<a href="#content"><?php print t('Skip to content'); ?></a>
				</div>
				
    <?php if ($leaderboard): ?>
	   <!-- LEADERBOARD -->
      <div id="leaderboard" class="width-48-950 last nofloat">
        <?php print $leaderboard; ?>
      </div> <!-- /leaderboard -->
    <?php endif; ?>
				
    <?php if ($logo || $site_name || $site_slogan || $search_box): ?>
	   <!-- HEADER -->
      <div id="header" class="width-48-950 last nofloat">
						
        <?php if ($logo || $site_name || $site_slogan): ?>
										<div class="branding width-40-790">
												<?php 
														if ($logo) {
																print $logo;
														}
														else {
																print $site_name;
														}
												?>        
												<?php if ($site_slogan): ?>
														<em><?php print $site_slogan; ?></em>
												<?php endif; ?>
										</div> <!-- /branding -->
        <?php endif; ?>
								
								<?php if ($search_box): ?>
										<div id="search-box-top" class="clearfix">
												<a href="javascript:setHomepage('http://localhost')"><?php print t('Set As Homepage'); ?></a>
												<br/>
												<a href="javascript:addFavorite('http://localhost','十堰倍力汽车零部件有限公司')"><?php print t('Add To Bookmark'); ?></a>
												<br/>
												<br/>
												<br/>
												<br/>
												<span>
												<?php print t('Search this site'); print ':'?>
												</span>
												<?php print $search_box; ?>
										</div> <!-- /search -->
								<?php endif; ?>
								
						</div> <!-- /header -->
				<?php endif; ?>

	 <!-- TOP NAVIGATION -->
	 <div id="main-navigation" class="width-48-950 last nofloat">

    <?php if ($primary_links || $suckerfish): ?>
      <!-- PRIMARY -->
      <div id="<?php print $primary_links ? 'primary-menu' : 'suckerfish' ; ?>" class="width-46-910">
        <?php 
					     if ($primary_links) {
		          print theme('links', $primary_links); 
				      }
				      elseif (!empty($suckerfish)) {
				        print $suckerfish;
				      }
        ?>
      </div> <!-- /primary -->
    <?php endif; ?>
	
	   <!-- FEED ICON / RSS -->
    <div class="feed-icons width-2-30 last clearfix">
      <!--
      <a href="<?php print $base_path; ?>rss.xml" class="feed-icon">
		    <img src="<?php print $base_path . $directory; ?>/images/feed.png" alt="Syndicate content" title="RSS Feed" width="16" height="16" />
		    </a> -->
    </div> <!-- /rss icon -->
  </div>

  <?php if ($secondary_links): ?> 
	   <!-- SECONDARY -->
    <div id="secondary-menu" class="width-48-950 last nofloat">
	     <?php print theme('links', $secondary_links); ?>
	   </div>
  <?php endif; ?>

	 <?php if ($header): ?>
    <div id="header" class="width-48-950 last nofloat">
      <?php print $header; ?>
    </div> <!-- /header -->
  <?php endif; ?>

	 <?php if ($content_top_full_width || $content_top_left || $content_top_content): ?>
    <!-- CONTENT TOP -->
	   <div id="content-top" class="width-48-950 last nofloat">
				
	     <?php if ($content_top_full_width): ?>
		      <div id="content-top-full-width" class="width-48-950 last nofloat">
	         <?php print $content_top_full_width; ?>
		      </div> <!-- /content-top-full-width -->
		    <?php endif; ?>
						
      <?php if ($content_top_left): ?>
        <div class="content-top-col-1 width-24-470">
          <?php print $content_top_left; ?>
        </div> <!-- /content-top-col-1 -->
      <?php endif; ?>
		
	     <?php if ($content_top_right): ?>
        <div class="content-top-col-2 width-24-470 last">
          <?php print $content_top_right; ?>
        </div> <!-- /content-top-col-2 -->
      <?php endif; ?>
						
    </div> <!-- /content-top -->
	 <?php endif; ?>
	
	 <!-- MAIN CONTENT -->
  <div id="col_wrapper" class="width-960">
	   <?php if ($left): ?>
	     <!-- LEFT -->
      <div id="left" class="width-10-190">
        <?php print $left; ?>
      </div> <!-- /left -->
    <?php endif; ?>
	   <!-- CONTENT -->
      <div id="content" class="<?php print newswire_col_width($left, $content, $right, $right_2); ?>">
        
								<?php if ($main_content_top): ?>
		        <div id="main-content-top">
								    <?php print $main_content_top; ?>
										</div>
		      <?php endif; ?>
								
								<?php print $breadcrumb; ?>
								
        <?php if ($title): ?>
		        <?php print $title; ?>
        <?php endif; ?>
								
        <?php if ($messages): ?>
		        <div id="messages"><?php print $messages; ?></div>
		      <?php endif; ?>
								
        <?php if ($tabs): ?>
          <div class="tabs"><?php print $tabs; ?></div>
        <?php endif; ?>
								
        <?php print $help; ?>
								
        <?php if ($mission): ?>
          <div class="mission"><?php print $mission; ?></div>
        <?php endif; ?>
								
		      <?php print $content; ?> 

								<?php if ($main_content_bottom): ?>
		        <div id="main-content-bottom">
								    <?php print $main_content_bottom; ?>
										</div>
		      <?php endif; ?>
								
      </div> <!-- /content -->

    <?php if (($right_top_box || $right_bottom_box) && ($right_2 && $right)): ?>
      <div id="right-col-wrapper" class="width-20-390 last">
        <?php if (($right_top_box) && ($right_2 && $right)): ?>
					     <div id="right-top-box" class="width-20-390 last nofloat">
						      <?php print $right_top_box; ?>
					     </div> <!-- /right 2 -->
			     <?php endif; ?>
		  <?php endif; ?>

						<?php if ($right_2): ?>
								<!-- RIGHT 2 -->
								<div id="right_2" class="width-10-190">
										<?php print $right_2; ?>
								</div> <!-- /right 2 -->
						<?php endif; ?>

						<?php if ($right): ?>
								<!-- RIGHT -->
								<div id="right" class="width-10-190 last">
										<?php print $right; ?>
								</div> <!-- /right -->
						<?php endif; ?>

						<?php if (($right_bottom_box) && ($right_2 && $right)): ?>
								<div id="right-bottom-box" class="width-20-390 last nofloat">
										<?php print $right_bottom_box; ?>
								</div> <!-- /right 2 -->
						<?php endif; ?>
	
		  <?php if (($right_top_box || $right_bottom_box) && ($right_2 && $right)): ?>
			   </div> <!-- /right cols wrapper  -->
		  <?php endif; ?> 	

	 </div> <!-- /col_wrapper-->

	 <?php if ($content_bottom_full_width || $content_bottom_left || $content_bottom_content): ?>
	   <!-- CONTENT BOTTOM -->
	   <div id="content-bottom" class="width-48-950 last nofloat">
      <?php if ($content_bottom_left): ?>
        <div class="content-bottom-col-1 width-24-470">
          <?php print $content_bottom_left; ?>
        </div> <!-- /content-bottom-col-1 -->
      <?php endif; ?>
	     <?php if ($content_bottom_right): ?>
        <div class="content-bottom-col-2 width-24-470 last">
          <?php print $content_bottom_right; ?>
        </div> <!-- /content-bottom-col-2 -->
      <?php endif; ?>
		    <?php if ($content_bottom_full_width): ?>
		      <div id="content-bottom-full-width" class="width-48-950 last nofloat">
	         <?php print $content_bottom_full_width; ?>
		      </div> <!-- /content-bottom-full-width -->
		    <?php endif; ?>
    </div> <!-- /content-bottom -->
	 <?php endif; ?>

		<!-- FOOTER -->
	 <div id="footer" class="wwidth-48-950 last nofloat">
	   <?php print $footer; ?>
	 </div>  <!-- /footer -->

		<?php if ($footer_message): ?>
	   <!-- FOOTER MESSAGE-->
	   <div id="footer-message" class="width-48-950 last nofloat small">
	     <!--<?php print $footer_message ?>-->
	     <?php print t('Copyright © 2009 Belead Inc, All Rights Reserved') ?>
	   </div>  <!-- /footer message -->
	 <?php endif; ?>

		<div id="adaptivethemes"><!--<a href="http://adaptivethemes.com">AdaptiveThemes</a>--></div>
    <?php print $closure ?>
  </div> <!-- /container -->

</body>
</html>
