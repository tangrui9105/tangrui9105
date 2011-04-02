<?php // $Id: comment-wrapper.tpl.php,v 1.2 2008/08/12 16:44:42 jmburnz Exp $
/**
 * @file comment-wrapper.tpl.php
 *
 * Theme implementation to wrap comments.
 *
 * @see template_preprocess_comment_wrapper()
 * @see theme_comment_wrapper()
 */
?>
<div id="comments">
  <?php if (!empty($content)): ?>
    <h3 id="comments-title"><?php print t('Comments'); ?></h3>
    <?php print $content; ?>
  <?php endif; ?>
</div>
