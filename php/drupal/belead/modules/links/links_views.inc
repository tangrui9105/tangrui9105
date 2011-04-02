<?php
/** @file
 *  $Id: links_views.inc,v 1.2.8.2 2009/01/30 02:45:49 syscrusher Exp $
 *
 * This include file defines hooks to make the Views module aware
 * of the Links Package data tables. This file is automatically
 * included by links.module if and only if the Views module is
 * installed.
 *
 * For more information about views, visit its project home page
 * at http://www.drupal.org/project/views .
 *
 * Author:  Scott Courtney (drupal.org user "syscrusher")
 */

/**************************************************
 * Hook implementations
 *************************************************/

/**
 * Implements hook_views_api()
 */
function links_views_api() {
  return array(
    'api' => 2.0,
  );
}

/**
 * Implements hook_views_data()
 */
function links_views_data() {

  // {links} table. The url_md5 field is not useful in Views, and is
  // intentionally omitted here.
  // TODO: last_click_time will be added in a future release, since
  // it needs a special display handler.
  $links = array(
    'table' => array(
      'group' => t('Links'),
      'base' => array(
        'field' => 'lid',
        'title' => t('Link'),
        'help' => t('Links are URLs stored in a central table. Each URL is stored just once, even if many nodes refer to it.'),
        'weight' => 0,
      ),
    ),
    'lid' => array(
      'title' => t('Lid'),
      'help' => t('The link ID of the link.'),
      'field' => array(
         'click sortable' => TRUE,
      ),
      'argument' => array(
        'name field' => 'link_title',
        'numeric' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'url' => array(
      'title' => t('URL'),
      'help' => t('The URL of the destination page. This may be a local Drupal path or an absolute URL.'),
      'field' => array(
         'click sortable' => TRUE,
      ),
    ),
    'link_title' => array(
      'title' => t('Link title'),
      'help' => t('This is the default (master) title for the link stored in the central links table. Nodes referring to the link may override this locally.'),
      'field' => array(
         'click sortable' => TRUE,
      ),
    ),
  );

  // {links_node} table, which is not a base table.
  $links_node = array(
    'lid' => array(
      'title' => t('Lid'),
      'help' => t('The link ID of the link.'),
      'field' => array(
         'click sortable' => TRUE,
      ),
      'argument' => array(
        'name field' => 'link_title',
        'numeric' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'nid' => array(
    ),
    'link_title' => array(
      'title' => t('Link title (local)'),
      'help' => t('This local title, if the node referring to the link overrides the master title. This field is empty if the master title is to be used.'),
      'field' => array(
         'click sortable' => FALSE,
      ),
    ),
    'clicks' => array(
      'title' => t('Click count'),
      'help' => t('If the site administrator has enabled click-counting, this field tallies the number of times users have visited this link from this particular referring instance of it.'),
      'field' => array(
        'click sortable' => TRUE,
      ),
    ),
  );

  return array(
    'links' => $links,
    'links_node' => $links_node,
  );
}
