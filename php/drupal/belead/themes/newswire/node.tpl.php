<?php // $Id: node.tpl.php,v 1.3 2008/08/21 21:58:40 jmburnz Exp $ 
/**
 * @file node.tpl.php
 *
 * Theme implementation to display a node.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 */
?>
<div class="node <?php print $node_classes; ?>" id="node_<?php print $node->nid; ?>">
  <?php if ($page == 0): ?>	
    <h2><a href="<?php print $node_url; ?>" rel="bookmark"><?php print $title; ?></a></h2>
  <?php endif; ?>		
  <?php if ($unpublished): ?>
    <div class="unpublished"><?php print t('Unpublished'); ?></div>
  <?php endif; ?>
  <?php if ($submitted): ?>
    <!--<h4 class="meta"><abbr title="<?php print format_date($node->created, 'custom', "l, F j, Y - H:i"); ?>"><?php print format_date($node->created, 'custom', "F j, Y"); ?></abbr> <?php print t('by'); ?> <em><?php print $name; ?></em></h4>-->
  <?php endif; ?>
  <?php if(!empty($picture) && ($node->type != 'poll')): ?>
    <div class="picture">
      <?php print $picture; ?>
    </div>
  <?php endif; ?>
  <?php print $content; ?>
  <?php if ($page == 1): ?>
    <!--<h5 class="permalink"><a href="<?php print $node_url; ?>" rel="bookmark"><?php print t('Permalink'); ?></a></h5>-->
  <?php endif; ?>
  <?php if (count($taxonomy)): ?>
    <div class="tags"><?php print $terms; ?></div>
  <?php endif; ?>
  <?php if ($links): ?>
    <div class="actions"><?php print $links; ?></div>
  <?php endif; ?>
</div> <!-- /node -->
