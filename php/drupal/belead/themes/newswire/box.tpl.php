<?php // $Id: box.tpl.php,v 1.2 2008/08/12 16:44:42 jmburnz Exp $ 
/**
 * @file box.tpl.php
 * 
 * Theme implementation to display a box.
 *
 * @see template_preprocess()
 */
?>
<div class="box">
  <div class="box-wrapper">
    <?php if ($title): ?>
      <h2 class="title"><?php print $title; ?></h2>
    <?php endif; ?>
    <div class="content">
      <?php print $content; ?>
    </div>
  </div> <!-- /box-wrapper -->
</div> <!-- /box -->
