<?php
// $Id: admin.inc,v 1.1.2.7 2009/06/16 04:55:21 pasqualle Exp $

/**
 * @file
 * The administration interface.
 */

/**
 * Header of the translation table.
 *
 * @param $languages
 *   languages to translate to
 *
 * @return
 *   header row for theme_table
 */
function _translation_table_get_header($languages) {
  $header = array(array('data' => t('Original'), 'sort' => 'asc', 'field' => 'source'));

  foreach ($languages as $lang_code => $lang_name) {
    $header[] = array('data' => $lang_name);
  }

  $header[] = array('data' => t('Operations'), 'colspan' => 3);
  return $header;
}

/**
 * One row of the translation table.
 *
 * @param $source
 *   source string record
 * @param $languages
 *   languages to translate to
 * @return
 *   table row for theme_table
 */
function _translation_table_row($source, $languages) {
  $form['source'] = array(
    '#type' => 'markup',
    '#value' => check_plain($source->source),
  );
  $form['location'] = array(
    '#type' => 'value',
    '#value' => check_plain($source->location),
  );

  foreach ($languages as $lang_code => $lang_name) {
    $translation = db_result(db_query("SELECT lt.translation FROM {locales_target} lt WHERE lt.lid = %d AND lt.language = '%s'", $source->lid, $lang_code));
    $form[$lang_code] = array(
      '#type' => 'textfield',
      '#default_value' => $translation,
      '#size' => 35,
      '#maxlength' => NULL,
    );
  }
  return $form;
}

/**
 * Menu callback; Admin form for menu translation.
 */
function translation_table_menu_form(&$form_state) {
  $languages_selected = isset($_SESSION['translation_table']['languages_selected']) ? $_SESSION['translation_table']['languages_selected'] : locale_language_list('name', FALSE);

  $form['filter'] = translation_table_menu_filter($languages_selected);
  $form['admin'] = translation_table_menu_filtered_form($languages_selected);
  $form['#submit'][] = 'translation_table_menu_form_submit';
  $form['#submit'][] = 'translation_table_submit_translations';
  return $form;
}

/**
 * Form for menu translation.
 * Note: If the menu string is not in the locales_source table, then it won't be
 * displayed.
 *
 * @param $languages
 *   languages to translate to
 */
function translation_table_menu_filtered_form($languages) {
  $header = _translation_table_get_header($languages);

  $sql = "SELECT ls.lid, ls.source, ls.location FROM {locales_source} ls WHERE ls.textgroup = 'menu'";
  $sql .= tablesort_sql($header);

  $form['strings']['#tree'] = TRUE;
  $form['#cache'] = TRUE;

  $form['header'] = array(
    '#type' => 'value',
    '#value' => $header,
  );
  $result = pager_query($sql, 50, 0);

  while ($source = db_fetch_object($result)) {
    if (strlen(trim($source->source)) > 0) {
      $form['strings'][$source->lid] = _translation_table_row($source, $languages);
    }
  }

  $form['languages'] = array(
    '#type' => 'value',
    '#value' => $languages,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  $form['pager'] = array('#value' => theme('pager', NULL, 50, 0));
  $form['#theme'] = 'translation_table';
  return $form;
}

/**
 * Menu callback; Admin form for taxonomy translation.
 */
function translation_table_taxonomy_form(&$form_state) {
  $languages_selected = isset($_SESSION['translation_table']['languages_selected']) ? $_SESSION['translation_table']['languages_selected'] : locale_language_list('name', FALSE);
  $vid = isset($_SESSION['translation_table']['vid']) ? $_SESSION['translation_table']['vid'] : -1;

  $form['filter'] = translation_table_taxonomy_filter($languages_selected, $vid);
  $form['admin'] = translation_table_taxonomy_filtered_form($languages_selected, $vid);
  $form['#submit'][] = 'translation_table_taxonomy_form_submit';
  $form['#submit'][] = 'translation_table_submit_translations';
  return $form;
}

/**
 * Form for taxonomy translation.
 * Note: If term and vocabulary strings are not in the locales_source table,
 * then they won't be displayed.
 *
 * @param $languages
 *   languages to translate to
 * @param $vid
 *   -1: show vocabulary names only
 *    0: show all
 *    else: filter by vocabulary ID
 */
function translation_table_taxonomy_filtered_form($languages, $vid) {
  $header = _translation_table_get_header($languages);

  switch ($vid) {
    case 0:
      $sql = "SELECT ls.lid, ls.source, ls.location FROM {locales_source} ls WHERE ls.textgroup = 'taxonomy'";
      $sql .= tablesort_sql($header);
      $result = pager_query($sql, 50, 0);
      break;

    case -1:
      $sql = "SELECT ls.lid, ls.source, ls.location FROM {locales_source} ls LEFT JOIN {i18n_strings} s ON ls.lid = s.lid WHERE s.type = 'vocabulary'";
      $sql .= tablesort_sql($header);
      $result = pager_query($sql, 50, 0);
      break;

    default:
      $sql = "SELECT ls.lid, ls.source, ls.location FROM {locales_source} ls LEFT JOIN {i18n_strings} s ON ls.lid = s.lid WHERE s.type = 'term' AND s.objectid IN (SELECT td.tid FROM {term_data} td WHERE td.vid = %d)";
      $sql .= tablesort_sql($header);
      $result = pager_query($sql, 50, 0, NULL, $vid);
      break;
  }

  $form['strings']['#tree'] = TRUE;
  $form['#cache'] = TRUE;

  $form['header'] = array(
    '#type' => 'value',
    '#value' => $header,
  );

  while ($source = db_fetch_object($result)) {
    if (strlen(trim($source->source)) > 0) {
      $form['strings'][$source->lid] = _translation_table_row($source, $languages);
    }
  }

  $form['languages'] = array(
    '#type' => 'value',
    '#value' => $languages,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  $form['pager'] = array('#value' => theme('pager', NULL, 50, 0));
  $form['#theme'] = 'translation_table';
  return $form;
}

/**
 * Menu callback; Admin form for node type translation.
 */
function translation_table_nodetype_form(&$form_state) {
  $languages_selected = isset($_SESSION['translation_table']['languages_selected']) ? $_SESSION['translation_table']['languages_selected'] : locale_language_list('name', FALSE);
  $node_type = isset($_SESSION['translation_table']['node_type']) ? $_SESSION['translation_table']['node_type'] : 0;

  $form['filter'] = translation_table_nodetype_filter($languages_selected, $node_type);
  $form['admin'] = translation_table_nodetype_filtered_form($languages_selected, $node_type);
  $form['#submit'][] = 'translation_table_nodetype_form_submit';
  $form['#submit'][] = 'translation_table_submit_translations';
  return $form;
}

/**
 * Form for node type translation.
 * Note: If the node type is not in the locales_source table, then it won't be
 * displayed.
 *
 * @param $languages
 *   languages to translate to
 * @param $node_type
 *    0: show all
 *    else: filter by node type
 */
function translation_table_nodetype_filtered_form($languages, $node_type) {
  $header = _translation_table_get_header($languages);

  switch ($node_type) {
    case '0':
      $sql = "SELECT ls.lid, ls.source, ls.location FROM {locales_source} ls WHERE ls.textgroup = 'nodetype'";
      $sql .= tablesort_sql($header);
      $result = pager_query($sql, 50, 0);
      break;

    default:
      $sql = "SELECT ls.lid, ls.source, ls.location FROM {locales_source} ls WHERE ls.textgroup = 'nodetype' AND ls.location LIKE 'type:%s%'";
      $sql .= tablesort_sql($header);
      $result = pager_query($sql, 50, 0, NULL, $node_type);
      break;
  }

  $form['strings']['#tree'] = TRUE;
  $form['#cache'] = TRUE;

  $form['header'] = array(
    '#type' => 'value',
    '#value' => $header,
  );

  while ($source = db_fetch_object($result)) {
    if (strlen(trim($source->source)) > 0) {
      $form['strings'][$source->lid] = _translation_table_row($source, $languages);
    }
  }

  $form['languages'] = array(
    '#type' => 'value',
    '#value' => $languages,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  $form['pager'] = array('#value' => theme('pager', NULL, 50, 0));
  $form['#theme'] = 'translation_table';
  return $form;
}

/**
 * Theme function for the translation table.
 *
 * @ingroup themeable
 */
function theme_translation_table($form) {
  $rows = array();
  $header = $form['header']['#value'];
  $languages = $form['languages']['#value'];

  foreach (element_children($form['strings']) as $key) {
    // Build the table row.
    $row = array();
    $row['data'][] = array('data' => drupal_render($form['strings'][$key]['source']), 'class' => 'translation-source');

    foreach ($languages as $lang_code => $lang_name) {
      $row['data'][] = array('data' => drupal_render($form['strings'][$key][$lang_code]), 'class' => 'translation-'. $lang_code);
    };
    $location = explode(':', $form['strings'][$key]['location']['#value']);
    if (count($location) == 3) {
      switch ($location[0]) {
        case 'term':
          $row['data'][] = l(t('Edit source'), 'admin/content/taxonomy/edit/term/'. $location[1], array('attributes' => array('title' => t('Edit term (@property)', array('@property' => t($location[2]))))));
          break;

        case 'vocabulary':
          $row['data'][] = l(t('Edit source'), 'admin/content/taxonomy/edit/vocabulary/'. $location[1], array('attributes' => array('title' => t('Edit vocabulary (@property)', array('@property' => t($location[2]))))));
          break;

        case 'item':
          $row['data'][] = l(t('Edit source'), 'admin/build/menu/item/'. $location[1] .'/edit', array('attributes' => array('title' => t('Edit menu item (@property)', array('@property' => t($location[2]))))));
          break;

        case 'type':
          $node_types = node_get_types('names');
          $node_type = isset($node_types[$location[1]]) ? $node_types[$location[1]] : $location[1];
          $row['data'][] = l(t('Edit source'), 'admin/content/node-type/'. $location[1], array('attributes' => array('title' => t('Edit @node_type (@property)', array('@node_type' => $node_type, '@property' => t($location[2]))))));
          break;

        default:
          $row['data'][] = '';
      }
    }
    else {
      $row['data'][] = '';
    }
    $row['data'][] = l(t('Translate'), 'admin/build/translate/edit/'. $key);
    $row['data'][] = l(t('Delete string'), 'admin/build/translate/delete/'. $key);

    $rows[] = $row;
  }

  $output = theme('table', $header, $rows, array('id' => 'translation-table'));
  if ($form['pager']['#value']) {
    $output .= drupal_render($form['pager']);
  }
  $output .= drupal_render($form);

  drupal_add_css(drupal_get_path('module', 'translation_table') .'/css/translation-table-admin.css');
  return $output;
}

/**
 * Menu filter.
 */
function translation_table_menu_filter($languages_selected) {
  $form['languages_selected'] = array(
    '#type' => 'select',
    '#title' => t('Languages'),
    '#description' => t('Select the languages to display.'),
    '#options' => locale_language_list('name', TRUE),
    '#default_value' => array_keys($languages_selected),
    '#multiple' => TRUE,
    '#prefix' => '<div id="language-filter">',
    '#suffix' => '</div>',
  );

  $form['filter'] = array(
    '#type' => 'submit',
    '#value' => t('Filter'),
  );

  $form['#theme'] = 'translation_table_menu_filter';
  return $form;
}

/**
 * Theme function for the menu filter form.
 *
 * @ingroup themeable
 */
function theme_translation_table_menu_filter($form) {
  $output = drupal_render($form);
  return $output;
}

/**
 * Taxonomy filter.
 */
function translation_table_taxonomy_filter($languages_selected, $vid) {
  $form['languages_selected'] = array(
    '#type' => 'select',
    '#title' => t('Languages'),
    '#description' => t('Select the languages to display.'),
    '#options' => locale_language_list('name', TRUE),
    '#default_value' => array_keys($languages_selected),
    '#multiple' => TRUE,
    '#prefix' => '<div id="language-filter">',
    '#suffix' => '</div>',
  );

  $vocabulary_options[0] = t('- Display all taxonomy strings -');
  $vocabulary_options[-1] = t('- Display vocabulary strings -');

  if (module_exists('taxonomy')) {
    if ($vocabularies = taxonomy_get_vocabularies()) {
      foreach ($vocabularies as $key => $vocabulary) {
        $vocabulary_options[$key] = $vocabulary->name;
      }
    }
  }

  $form['vid'] = array(
    '#type' => 'select',
    '#title' => t('Vocabulary'),
    '#description' => t('Select the vocabulary.'),
    '#options' => $vocabulary_options,
    '#default_value' => $vid,
  );

  $form['filter'] = array(
    '#type' => 'submit',
    '#value' => t('Filter'),
  );

  $form['#theme'] = 'translation_table_taxonomy_filter';
  return $form;
}

/**
 * Theme function for the vocabulary filter form.
 *
 * @ingroup themeable
 */
function theme_translation_table_taxonomy_filter($form) {
  $output = drupal_render($form);
  return $output;
}

/**
 * Node type filter.
 */
function translation_table_nodetype_filter($languages_selected, $node_type) {
  $form['languages_selected'] = array(
    '#type' => 'select',
    '#title' => t('Languages'),
    '#description' => t('Select the languages to display.'),
    '#options' => locale_language_list('name', TRUE),
    '#default_value' => array_keys($languages_selected),
    '#multiple' => TRUE,
    '#prefix' => '<div id="language-filter">',
    '#suffix' => '</div>',
  );

  $form['node_type'] = array(
    '#type' => 'select',
    '#title' => t('Content type'),
    '#description' => t('Select the content types to display.'),
    '#options' => array_merge(array( 0 => t('- All -')), node_get_types('names')),
    '#default_value' => $node_type,
    '#prefix' => '<div id="nodetype-filter">',
    '#suffix' => '</div>',
  );

  $form['filter'] = array(
    '#type' => 'submit',
    '#value' => t('Filter'),
  );

  $form['#theme'] = 'translation_table_nodetype_filter';
  return $form;
}

/**
 * Theme function for the node type filter form.
 *
 * @ingroup themeable
 */
function theme_translation_table_nodetype_filter($form) {
  $output = drupal_render($form);
  return $output;
}

/**
 * Submit handler for the menu translation form.
 */
function translation_table_menu_form_submit($form, &$form_state) {
  switch ($form_state['clicked_button']['#id']) {
    case 'edit-filter':
    case 'edit-submit':
      $_SESSION['translation_table']['languages_selected'] = array_intersect_key(locale_language_list('name', TRUE), $form_state['values']['languages_selected']);
      break;
  }
}

/**
 * Submit handler for the taxonomy translation form.
 */
function translation_table_taxonomy_form_submit($form, &$form_state) {
  switch ($form_state['clicked_button']['#id']) {
    case 'edit-filter':
    case 'edit-submit':
      $_SESSION['translation_table']['vid'] = $form_state['values']['vid'];
      $_SESSION['translation_table']['languages_selected'] = array_intersect_key(locale_language_list('name', TRUE), $form_state['values']['languages_selected']);
      break;
  }
}

/**
 * Submit handler for the node type translation form.
 */
function translation_table_nodetype_form_submit($form, &$form_state) {
  switch ($form_state['clicked_button']['#id']) {
    case 'edit-filter':
    case 'edit-submit':
      $_SESSION['translation_table']['node_type'] = $form_state['values']['node_type'];
      $_SESSION['translation_table']['languages_selected'] = array_intersect_key(locale_language_list('name', TRUE), $form_state['values']['languages_selected']);
      break;
  }
}

/**
 * Submit handler for the translation table.
 */
function translation_table_submit_translations($form, &$form_state) {
  switch ($form_state['clicked_button']['#id']) {
    case 'edit-submit':
      $language_list = locale_language_list('language', TRUE);
      foreach ($form_state['values']['strings'] as $lid => $values) {
        foreach ($values as $lang_code => $translation) {
          if (in_array($lang_code, $language_list)) {
            _translation_table_update_translation($lid, $lang_code, $translation);
          }
        }
      }
      break;
  }
}

/**
 * Update, create or delete translation as needed.
 */
function _translation_table_update_translation($lid, $lang_code, $translation) {
  if ($translation == '') {
    db_query("DELETE FROM {locales_target} WHERE lid = %d AND language = '%s'", $lid, $lang_code);
    return;
  }
  db_query("UPDATE {locales_target} SET translation = '%s' WHERE lid = %d AND language = '%s'", $translation, $lid, $lang_code);
  if (!db_affected_rows()) {
    db_query("INSERT INTO {locales_target} (lid, language, translation) VALUES (%d, '%s', '%s')", $lid, $lang_code, $translation);
  }
}
