<?php // $Id: block.tpl.php,v 1.2 2008/08/12 16:44:42 jmburnz Exp $
/**
 * @file block.tpl.php
 *
 * Theme implementation to display a block.
 *
 * @see template_preprocess()
 * @see template_preprocess_block()
 */
?>
<div id="block-<?php print $block->module .'-'. $block->delta; ?>" class="block <?php print $block_classes; ?>">
  <div class="block-wrapper">
    <?php if ($block->subject): ?>
      <h3 class="title"><span><?php print $block->subject; ?></span></h3>
    <?php endif; ?>
    <div class="content">
      <?php print $block->content; ?>
    </div>
  <?php print $edit_links; ?>
  </div> <!-- /block-warpper -->
</div> <!-- /block -->
