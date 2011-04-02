<?php
// $Id:
function phptemplate_settings($saved_settings) {
  $settings = theme_get_settings('newswire');
  $defaults = array(
    'newswire_style' => 'newswire_rubinator',
  );
  $settings = array_merge($defaults, $settings);
  $form['newswire_style'] = array(
    '#type' => 'select',
    '#title' => t('Style'),
    '#default_value' => $settings['newswire_style'],
    '#options' => array(
	  'newswire_rubinator' => t('Rubinator'),
      'newswire_surfnsand' => t('Surf-n-Sand'),
	  'newswire_rusky' => t('Rusky'),
      'newswire_washington' => t('Washington'),
	  'newswire_sunset' => t('Sunset'),
      'newswire_custom-gray' => t('Custom - Gray'),
      'newswire_custom-tan' => t('Custom - Tan'),
    ),
  );
  return $form;
}