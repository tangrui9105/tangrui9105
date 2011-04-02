<?php
// $Id: tracker2.admin.inc,v 1.1.2.2 2009/02/19 16:02:31 straussd Exp $

/**
 * @file
 * Admin page callbacks for the tracker2 module.
 */

/**
 * Menu callback argument. Creates the tracker2 administration form.
 */
function tracker2_admin() {
  $max_nid = variable_get('tracker2_index_nid', 0);
  $form['max_nid'] = array(
    '#value' => $max_nid ? t('Max node ID for indexing on the next cron run: @max', array('@max' => $max_nid)) : t('Existing nodes have finished tracker indexing.'),
  );

  $form['tracker2_batch_size'] = array(
    '#title' => t('Batch size'),
    '#description' => t('Number of nodes to index during each cron run.'),
    '#type' => 'textfield',
    '#size' => 6,
    '#maxlength' => 7,
    '#default_value' => variable_get('tracker2_batch_size', 1000),
    '#required' => TRUE,
  );

  $form['tracker2_pager'] = array(
    '#title' => t('Nodes per page'),
    '#description' => t('Number of nodes to show per page of the tracker listing.'),
    '#type' => 'textfield',
    '#size' => 6,
    '#maxlength' => 7,
    '#default_value' => variable_get('tracker2_pager', 25),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}

/**
 * Validate callback.
 */
function tracker2_admin_validate($form, &$form_state) {
  // Max_nid is just a markup field and should not cause a variable to be set.
  unset($form_state['values']['max_nid']);

  // The variables must be non-negative and numeric.
  if (!is_numeric($form_state['values']['tracker2_batch_size']) || $form_state['values']['tracker2_batch_size'] <= 0) {
    form_set_error('tracker2_batch_size', t('The batch size must be a number and greater than zero.'));
  }
  if (!is_numeric($form_state['values']['tracker2_pager']) || $form_state['values']['tracker2_pager'] <= 0) {
    form_set_error('tracker2_pager', t('The nodes per page must be a number and greater than zero.'));
  }
}
