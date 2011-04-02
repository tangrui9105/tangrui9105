<?php // $Id$

/**
 * @file
 * Main template file
 *
 * @see template_preprocess_page(), preprocess/preprocess-page.inc
 * http://api.drupal.org/api/function/template_preprocess_page/6
 */
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
  <html xmlns="http://www.w3.org/1999/xhtml" lang="<?php print $language->language; ?>" xml:lang="<?php print $language->language; ?>">
    <head>
      <?php print $head; ?>
      <title><?php print $head_title; ?></title>
      <?php print $styles; ?>
      <?php print $ie_styles; ?>
      <script type="text/javascript" src="<?php print $base_path . $directory; ?>/scripts/homefav.js"></script>
      <?php print $scripts; ?>
    </head>
  <body<?php print $attributes; ?>>
  <?php if (!empty($admin)) print $admin; // support for: http://drupal.org/project/admin ?>
  <div id="wrapper">
    <div<?php print $header_attributes; ?>>
      <div id="header-inner">
	<table class="site-table">
	<tr class="site-tr">
	<td class="site-td">
        <a href="<?php print $base_path; ?>" title="<?php print $site_name; ?>" id="logo"><img class="logo1" src="sites/default/files/logo1.png" height="155px"/></a>
	</td>
	<td class="site-td">
  	<div id="site-name">
	<?php print t('Shanghai Luopin Mechanical & Electrical Equipment Co., Ltd.')?>
	</div>
        <img class="logo2" src="sites/default/files/logo2.png"/>
	</td>
	<td class="site-td-last">
  	<div id="site-home">
		<a href="javascript:setHomepage('http://www.luopin.net')"><?php print t('Set As Homepage'); ?></a>
	</div>
  	<div id="site-fav">
		<a href="javascript:addFavorite('http://www.luopin.net','Luopin')"><?php print t('Add To Bookmark'); ?></a>
	</div>
	<br/>
	<br/>
	<br/>
	<div id="site-search">
		<?php print $search_box;?>
	</div>
	</td>
	</tr>
	</table>
	<!--
        <span id="site-name"> <a href="<?php print $base_path; ?>" title="<?php print $site_name; ?>">上海罗频机电设备有限公司</a> </span>
        <span id="site-name-english"> <a href="<?php print $base_path; ?>" title="<?php print $site_name; ?>">Shanghai Luopin Mechanical & Electrical Equipment Co., Ltd.</a> </span>
	-->
      </div>
    </div>
    <?php if ($primary_links): ?>
      <div id="navigation"><?php print $primary_links; ?></div>
    <?php endif; ?>
    <div id="container" class="layout-region">
      <?php if ($left): ?>
        <div id="sidebar-left" class="sidebar">
          <div class="inner">
            <?php print $left; ?>
          </div>
        </div>
      <!-- END HEADER -->
      <?php endif; ?>
      <div id="main">
        <div class="main-inner">
          <?php if ($breadcrumb): ?>
            <div class="breadcrumb clearfix"><?php print $breadcrumb; ?></div>
          <?php endif; ?>
          <?php if ($show_messages && $messages != ""): ?>
          <?php print $messages; ?>
          <?php endif; ?>
          <?php if ($is_front && $mission): ?>
            <div class="mission"><?php print $mission; ?></div>
          <?php endif; ?>
          <?php if ($contenttop): ?>
            <div id="content-top"><?php print $contenttop; ?></div>
            <!-- END CONTENT TOP -->
          <?php endif; ?>
          <?php if ($title): ?>
            <h1 class="title"><?php print $title; ?></h1>
          <?php endif; ?>
          <?php if ($help): ?>
            <div class="help"><?php print $help; ?></div>
          <?php endif; ?>
          <?php print $tabs; ?>
	  <?php print $content; ?>
          <!-- END CONTENT -->
	  <!--
          <?php print $feed_icons; ?>
          <?php if ($contentbottom): ?>
            <div id="content-bottom"><?php print $contentbottom; ?></div>
          <?php endif; ?>
	  -->
        </div>
        <!-- END MAIN INNER -->
      </div>
      <!-- END MAIN -->
      <?php if ($right): ?>
        <div id="sidebar-right" class="sidebar">
          <div class="inner">
          <?php print $right; ?>
          </div>
        </div>
      <!-- END SIDEBAR RIGHT -->
      <?php endif; ?>
    </div>
    <!-- END CONTAINER -->
    <div class="push">&nbsp;</div>
  </div>
  <!-- END WRAPPER -->
  <div id="footer" class="layout-region">
    <div id="footer-inner">
      <p>
      <?php print l(t('About Luopin'), 'about'); ?></a>
      &nbsp;|&nbsp;
      <?php print l(t('Site Navigation'), 'site'); ?></a>
      &nbsp;|&nbsp;
      <?php print l(t('Help Center'), 'help'); ?></a>
      &nbsp;|&nbsp;
      <?php print l(t('Related Laws'), 'laws'); ?></a>
      &nbsp;|&nbsp;
      <?php print l(t('Cooperation'), 'cooperation'); ?></a>
      </p>
      <!--<?php print $footer_message; ?>-->
      <?php print t('Shanghai Luopin Mechanical & Electrical Equipment Co., Ltd. All Rights Reserved'); ?>
    </div>
  </div>
  <?php print $closure; ?>
  </body>
</html>
