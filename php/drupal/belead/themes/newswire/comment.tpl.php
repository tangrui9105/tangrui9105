<?php // $Id: comment.tpl.php,v 1.5 2008/08/25 22:32:41 jmburnz Exp $ 
/**
 * @file comment.tpl.php
 *
 * Theme implementation for comments.
 *
 * @see template_preprocess_comment()
 * @see theme_comment()
 */
?>
<div class="comment <?php print $comment_classes; ?> clearfix">
  <?php if ($title): ?>
    <h3 class="title"><?php print $title; if (!empty($new)): ?> <span class="new"><?php print $new; ?></span><?php endif; ?></h3>
  <?php elseif (!empty($new)): ?>
    <div class="new"><?php print $new; ?></div>
  <?php endif; ?>
  <?php if ($unpublished): ?>
    <div class="unpublished"><?php print t('Unpublished'); ?></div>
  <?php endif; ?>
  <?php if ($submitted): ?>
    <h4 class="meta">
	  <abbr title="<?php print format_date($comment->timestamp, 'custom', "l, F j, Y - H:i"); ?>"><?php print format_date($comment->timestamp, 'custom', "F j, Y"); ?></abbr> <?php print t('by'); ?> <em><?php print theme('username', $comment); ?></em>, <span class="time-ago"><?php print t('!date ago', array( '!date' => format_interval(time() - $comment->timestamp))); ?></span><br />
	  <span class="comment-id"><?php print t('Comment id: '). $comment->cid; ?></span>
	</h4>
  <?php endif; ?>
  <?php if(!empty($picture)): ?>
    <div class="picture">
      <?php print $picture; ?>
    </div>
  <?php endif; ?>
    <div class="comment-content <?php if ($picture) print 'with-picture'; ?>">
      <?php print $content; ?>
    </div> <!-- /comment content -->
    <?php if ($links): ?>
      <div class="links">
        <?php print $links; ?>
      </div>
    <?php endif; ?>
</div> <!-- /comment -->