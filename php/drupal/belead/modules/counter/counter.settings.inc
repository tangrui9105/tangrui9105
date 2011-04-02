<?php
// $Id: counter.settings.inc,v 1.3 2009/03/27 11:06:28 thenicespider Exp $
/**
 * @file
 * Settings page callback file for the counter module.
 */

/**
 * Menu callback;
 */
 
function counter_admin_settings() {
  $form = array();
  // only administrators can access this function
  
  // Generate the form - settings applying to all patterns first
  $form['counter_settings'] = array(
    '#type' => 'fieldset',
    '#weight' => -30,
    '#title' => t('Basic settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#description' => l(t('Click here to access: Site Counter Report'), "counter/report")
  );
  
  $form['counter_settings']['counter_show_site_counter'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Site Counter'),
    '#default_value' => variable_get('counter_show_site_counter', 1),
    '#description' => t('Show Site Counter')
  );    
    
  $form['counter_settings']['counter_show_unique_visitor'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Unique Visitors'),
    '#default_value' => variable_get('counter_show_unique_visitor', 1),
    '#description' => t('Show Unique Visitors based on their IP')
  );
  
  $form['counter_settings']['counter_registered_user'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Registered Users'),
    '#default_value' => variable_get('counter_registered_user', 1),
    '#description' => t('Show Registered Users')
  );
  
  $form['counter_settings']['counter_unregistered_user'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Unregistered Nodes'),
    '#default_value' => variable_get('counter_unregistered_user', 1),
    '#description' => t('Show Unregistered Users')
  );
  
  $form['counter_settings']['counter_published_node'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Published Nodes'),
    '#default_value' => variable_get('counter_published_node', 1),
    '#description' => t('Show Published Nodes')
  );
  
  $form['counter_settings']['counter_unpublished_node'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Unpublished Users'),
    '#default_value' => variable_get('counter_unpublished_node', 1),
    '#description' => t('Show Unpublished Users')
  );
  
  $form['counter_settings']['counter_show_server_ip'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Web Server IP'),
    '#default_value' => variable_get('counter_show_server_ip', 1),
    '#description' => t('Show Web Server IP')
  );
  
	$form['counter_settings']['counter_show_ip'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Client IP'),
    '#default_value' => variable_get('counter_show_ip', 1),
    '#description' => t('Show Client IP')
  );
 
  $form['counter_settings']['counter_show_counter_since'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Sice Counter Since'),
    '#default_value' => variable_get('counter_show_counter_since', 1),
    '#description' => t('Show the first entry date in the Site Counter')
  );
  
  $form['counter_advanced'] = array(
    '#type' => 'fieldset',
    '#weight' => -20,
    '#title' => t('Advanced settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#description' => l(t('Click here to access: Site Counter Report'), "counter/report")
  );
  
  $form['counter_advanced']['counter_show_administer_only'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Site Counter Result for Administer group only'),
    '#default_value' => variable_get('counter_show_administer_only', 0),
    '#description' => t("Show Site Counter Result for group with 'administer counter' rights only. This setting usefull if you want to hide Counter block from public users")
  );    
  
  $form['counter_advanced']['counter_record_interval'] = array(
      '#type' => 'select',
      '#title' => t('Save record interval'),
      '#default_value' => variable_get('counter_record_interval', 0),
      '#options' => array('day', 'minute', 'second'),
      '#description' => t("Counter will save access per interval, if you choose 'day' then same IP that access same page will be "
	                     ."save as 1 record per day, i.e: "
						 ."<ul>"
						 ."<li>Per day &nbsp;&nbsp;&nbsp;&nbsp;: User A access 'node/12' 25 times per day --> save as 1 record</li>"
						 ."<li>Per minute: User A access 'node/12' 25 times on 22:03 and 5 times on 22:07 ---> save as 2 records</li>"
						 ."<li>Per second: User A access 'node/12' 2 times on 22:03:01 and 3 times on 22:03:02 ---> save as 2 records</li>"
						 ."</ul><b>Caution!</b>Set interval to second may cause your database size too big, because every second access will be saved"),
      );
      
  $form['counter_initial'] = array(
    '#type' => 'fieldset',
    '#weight' => -10,
    '#title' => t('Initial Values'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#description' => t("Set initial values for Site Counter.")
  );
  
  $form['counter_initial']['counter_initial_counter'] = array(
    '#type' => 'textfield',
    '#title' => t('Initial value of Site Counter'),
    '#default_value' => variable_get('counter_initial_counter', 0),
    '#description' => t('Initial value of Site Counter')
  );
  
  $form['counter_initial']['counter_initial_unique_visitor'] = array(
    '#type' => 'textfield',
    '#title' => t('Initial value of Unique Visitor'),
    '#default_value' => variable_get('counter_initial_unique_visitor', 0),
    '#description' => t('Initial value of Unique Visitor')
  );
  
  $form['counter_initial']['counter_initial_since'] = array(
    '#type' => 'textfield',
    '#title' => t("Replace 'Since' value with this string"),
    '#default_value' => variable_get('counter_initial_since', ''),
    '#description' => t("If you leave this field blank than Counter module will use the first date of Counter record. This field type is textfield, so you can enter: '2008-08-12 or 12 August 2008 06:39'.")
  );
  
  return system_settings_form($form);
}
