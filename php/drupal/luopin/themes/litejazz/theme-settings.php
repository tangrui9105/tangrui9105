<?php

function phptemplate_settings($saved_settings) {

  $settings = theme_get_settings('litejazz');

  $defaults = array(
    'litejazz_style' => 0,
    'litejazz_width' => 0,
    'litejazz_fixedwidth' => '850',
    'litejazz_breadcrumb' => 0,
    'litejazz_iepngfix' => 0,
    'litejazz_themelogo' => 0,
    'litejazz_fontfamily' => 0,
    'litejazz_customfont' => '',
    'litejazz_uselocalcontent' => 0,
    'litejazz_localcontentfile' => '',
    'litejazz_leftsidebarwidth' => '25',
    'litejazz_rightsidebarwidth' => '25',
    'litejazz_suckerfish' => 0,
    'litejazz_usecustomlogosize' => 0,
    'litejazz_logowidth' => '100',
    'litejazz_logoheight' => '100',
  );

  $settings = array_merge($defaults, $settings);

  $form['litejazz_style'] = array(
    '#type' => 'select',
    '#title' => t('Style'),
    '#default_value' => $settings['litejazz_style'],
    '#options' => array(
      'blue' => t('Blue'),
      'red' => t('Red'),
      'green' => t('Green'),
    ),
  );

  $form['litejazz_themelogo'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use Themed Logo'),
    '#default_value' => $settings['litejazz_themelogo'],
  );

  $form['litejazz_width'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use Fixed Width'),
    '#default_value' => $settings['litejazz_width'],
  );

  $form['litejazz_fixedwidth'] = array(
    '#type' => 'textfield',
    '#title' => t('Fixed Width Size'),
    '#default_value' => $settings['litejazz_fixedwidth'],
    '#size' => 5,
    '#maxlength' => 5,
  );

  $form['litejazz_breadcrumb'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Breadcrumbs'),
    '#default_value' => $settings['litejazz_breadcrumb'],
  );

  $form['litejazz_iepngfix'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use IE PNG Fix'),
    '#default_value' => $settings['litejazz_iepngfix'],
  );
  
  $form['litejazz_fontfamily'] = array(
    '#type' => 'select',
    '#title' => t('Font Family'),
    '#default_value' => $settings['litejazz_fontfamily'],
    '#options' => array(
       'Arial, Verdana, sans-serif' => t('Arial, Verdana, sans-serif'),
       '"Arial Narrow", Arial, Helvetica, sans-serif' => t('"Arial Narrow", Arial, Helvetica, sans-serif'),
       '"Times New Roman", Times, serif' => t('"Times New Roman", Times, serif'),
       '"Lucida Sans", Verdana, Arial, sans-serif' => t('"Lucida Sans", Verdana, Arial, sans-serif'),
       '"Lucida Grande", Verdana, sans-serif' => t('"Lucida Grande", Verdana, sans-serif'),
       'Tahoma, Verdana, Arial, Helvetica, sans-serif' => t('Tahoma, Verdana, Arial, Helvetica, sans-serif'),
       'Georgia, "Times New Roman", Times, serif' => t('Georgia, "Times New Roman", Times, serif'),
       'Custom' => t('Custom (specify below)'),
    ),
  );

  $form['litejazz_customfont'] = array(
    '#type' => 'textfield',
    '#title' => t('Custom Font-Family Setting'),
    '#default_value' => $settings['litejazz_customfont'],
    '#size' => 40,
    '#maxlength' => 75,
  );

  $form['litejazz_uselocalcontent'] = array(
    '#type' => 'checkbox',
    '#title' => t('Include Local Content File'),
    '#default_value' => $settings['litejazz_uselocalcontent'],
  );

  $form['litejazz_localcontentfile'] = array(
    '#type' => 'textfield',
    '#title' => t('Local Content File Name'),
    '#default_value' => $settings['litejazz_localcontentfile'],
    '#size' => 40,
    '#maxlength' => 75,
  );

  $form['litejazz_leftsidebarwidth'] = array(
    '#type' => 'textfield',
    '#title' => t('Left Sidebar Width'),
    '#default_value' => $settings['litejazz_leftsidebarwidth'],
    '#size' => 5,
    '#maxlength' => 5,
  );

  $form['litejazz_rightsidebarwidth'] = array(
    '#type' => 'textfield',
    '#title' => t('Right Sidebar Width'),
    '#default_value' => $settings['litejazz_rightsidebarwidth'],
    '#size' => 5,
    '#maxlength' => 5,
  );

  $form['litejazz_suckerfish'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use Suckerfish Menus'),
    '#default_value' => $settings['litejazz_suckerfish'],
  );

  $form['litejazz_usecustomlogosize'] = array(
    '#type' => 'checkbox',
    '#title' => t('Specify Custom Logo Size'),
    '#default_value' => $settings['litejazz_usecustomlogosize'],
  );

  $form['litejazz_logowidth'] = array(
    '#type' => 'textfield',
    '#title' => t('Logo Width'),
    '#default_value' => $settings['litejazz_logowidth'],
    '#size' => 5,
    '#maxlength' => 5,
  );

  $form['litejazz_logoheight'] = array(
    '#type' => 'textfield',
    '#title' => t('Logo Height'),
    '#default_value' => $settings['litejazz_logoheight'],
    '#size' => 5,
    '#maxlength' => 5,
  );

  return $form;
}


