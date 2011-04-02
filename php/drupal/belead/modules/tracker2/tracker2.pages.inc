<?php
// $Id: tracker2.pages.inc,v 1.1.2.2 2009/02/19 16:02:31 straussd Exp $

/**
 * @file
 * User page callbacks for the tracker2 module.
 */

/**
 * Menu callback. Prints a listing of active nodes on the site.
 */
function tracker2_page($account = NULL) {
  drupal_add_css(drupal_get_path('module', 'tracker2') .'/tracker2.css', 'module', 'all', FALSE);
  $nodes_per_page = variable_get('tracker2_pager', 25);

  if ($account) {
    $sql = "SELECT t2u.nid, t2u.changed AS last_activity FROM {tracker2_user} t2u WHERE t2u.published = 1 AND t2u.uid = %d ORDER BY t2u.changed DESC";
    $sql = db_rewrite_sql($sql, 't2u');
    $sql_count = "SELECT COUNT(t2u.nid) FROM {tracker2_user} t2u WHERE t2u.published = 1 AND t2u.uid = %d";
    $sql_count = db_rewrite_sql($sql_count, 't2u');
    $result = pager_query($sql, $nodes_per_page, 0, $sql_count, $account->uid);
  }
  else {
    $sql = "SELECT t2n.nid, t2n.changed AS last_activity FROM {tracker2_node} t2n WHERE t2n.published = 1 ORDER BY t2n.changed DESC";
    $sql = db_rewrite_sql($sql, 't2n');
    $sql_count = "SELECT COUNT(n.nid) FROM {node} n WHERE n.status = 1";
    $sql_count = db_rewrite_sql($sql_count);
    $result = pager_query($sql, $nodes_per_page, 0, $sql_count);
  }

  // This array acts as a placeholder for the data selected later
  // while keeping the correct order.
  $nodes = array();
  while ($node = db_fetch_object($result)) {
    $nodes[$node->nid] = $node;
  }
  return theme('tracker2_page', $nodes);
}

/**
 * Override-able output of the tracker2 listings.
 */
function theme_tracker2_page($nodes = array()) {
  if (!empty($nodes)) {
    // Now, get the data and put into the placeholder array
    $placeholders = array_fill(0, count($nodes), '%d');

    $result = db_query("SELECT n.nid, n.title, n.type, n.changed, n.uid, u.name, l.comment_count FROM {node} n 
      INNER JOIN {node_comment_statistics} l ON n.nid = l.nid INNER JOIN {users} u ON n.uid = u.uid 
      WHERE n.nid IN (". implode(',', $placeholders) .")", array_keys($nodes));
    while ($node = db_fetch_object($result)) {
      $node->last_activity = $nodes[$node->nid]->last_activity;
      $nodes[$node->nid] = $node;
    }

    // Finally display the data
    $rows = array();
    foreach ($nodes as $node) {
      // Determine the number of comments:
      $comments = 0;
      if ($node->comment_count) {
        $comments = $node->comment_count;

        if ($new = comment_num_new($node->nid)) {
          $comments .= '<br />';
          $comments .= l(format_plural($new, '1 new', '@count new'), 'node/'. $node->nid, array('fragment' => 'new'));
        }
      }

      $rows[] = array(
        check_plain(node_get_types('name', $node->type)),
        l($node->title, "node/$node->nid") .' '. theme('mark', node_mark($node->nid, $node->changed)),
        theme('username', $node),
        array('class' => 'replies', 'data' => $comments),
        t('!time ago', array('!time' => format_interval(time() - $node->last_activity)))
      );
    }
  }
  else {
    $rows[] = array(array('data' => t('No posts available.'), 'colspan' => '5'));
  }

  $header = array(t('Type'), t('Post'), t('Author'), t('Replies'), t('Last updated'));

  $output = '<div id="tracker">';
  $output .= theme('table', $header, $rows);
  $output .= theme('pager', NULL, variable_get('tracker2_pager', 25), 0);
  $output .= '</div>';
  return $output;
}

/**
 * Menu callback. Prints a listing of active nodes on the site per user.
 */
function tracker2_track_user() {
  if ($account = user_load(array('uid' => arg(1)))) {
    if ($account->status || user_access('administer users')) {
      drupal_set_title(check_plain($account->name));
      return tracker2_page($account);
    }
    else {
      drupal_access_denied();
    }
  }
  else {
    drupal_not_found();
  }
}
