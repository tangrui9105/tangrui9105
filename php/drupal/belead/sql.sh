#!/bin/bash
sed -n -e '1, 710p' drupal.sql > 1.sql
sed -n -e '711, 750p' drupal.sql > 2.sql
sed -n -e '751, 790p' drupal.sql > 3.sql
sed -n -e '791, 830p' drupal.sql > 4.sql
sed -n -e '831, 870p' drupal.sql > 5.sql
sed -n -e '871, 890p' drupal.sql > 6.sql
sed -n -e '891, 910p' drupal.sql > 7.sql
sed -n -e '911, 940p' drupal.sql > 8.sql
sed -n -e '941, 6000p' drupal.sql > 9.sql
sed -n -e '6001, 12000p' drupal.sql > 10.sql
sed -n -e '12001, 18000p' drupal.sql > 11.sql
sed -n -e '18001, 24000p' drupal.sql > 12.sql
sed -n -e '24001, 30000p' drupal.sql > 13.sql
sed -n -e '30001, 36000p' drupal.sql > 14.sql
sed -n -e '36001, $p' drupal.sql > 15.sql
