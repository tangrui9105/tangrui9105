Description
===========
Elements intends to become a library that provides complex form elements for developers to use in their modules.

Written by Heine Deelstra.

This module was commissioned by the NCRV (http://www.ncrv.nl/).

Elements provided
=================

1. tableselect
2. imagebutton (not working properly yet).


1. tableselect
===============
Provides a table with checkboxes or radios in the first column (similar to the table on admin/user/user).

$header = array(
  'field_key' => 'field_title',
  'field_key1' => 'field_title1',
);

$options = array(
  'id1'=> array(
    'field_key' => 'value',
    'field_key1' => 'another value',
  ),

  'id2'=> array(
    'field_key' => 'value',
    'field_key1' => 'another value',
  ),
);

$form['test_multiselect'] = array(
  '#type'=> 'tableselect',
  '#header' => $header,
  '#options'=> $options,
  '#default_value'=> array('id1' => ''),
);


$form['test_single_select'] = array(
  '#type'=> 'tableselect',
  '#header' => $header,
  '#options'=> $options,
  '#multiple' => FALSE,
  '#default_value'=> 'id1',
);

Properties tableselect
======================
#header
  The table header, an array of field_key => title pairs.
#options
  The data displayed in the table. Nested array of id => array pairs where the array is an array of field_key => value pairs.
#multiple
  Determines whether multiple values can be selected. Displays checkboxes when TRUE, radios when FALSE.
    Default: TRUE
#advanced_select
  Whether to provide advanced selection behaviour (SELECT ALL checkbox, SHIFT-select).
    Default: TRUE - when #multiple is TRUE.
    When #multiple is FALSE, always FALSE.
#default_value
  Provide an array of id => x pairs for the ids that should be selected by default when #multiple is TRUE.
  Provide the id as a scalar for the id that should be selected by default when #multiple is FALSE.