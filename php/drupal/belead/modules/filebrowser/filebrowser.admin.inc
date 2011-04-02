<?php
/* This file is part of "filebrowser".
 *    Copyright 2009, arNuméral
 *    Author : Yoran Brault
 *    eMail  : yoran.brault@bad_arnumeral.fr (remove bad_ before sending an email)
 *    Site   : http://www.arnumeral.fr/node/5
 * 
 * "filebrowser" is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * "filebrowser" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with "Broken Anchor for Node comments Module"; if not, write to the Free
 * Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA, or see the FSF site: http://www.fsf.org.
 */
 
function filebrowser_admin_settings() {
  $form['filebrowser_no_node_access'] = array (
    '#type' => 'checkbox',
    '#title' => t('Leave node permissions to an external module'),
      '#default_value' => filebrowser_get_no_node_access(), 
      '#description' => t("Check this if you are using an external permission module using node_access system (ex. nodeaccess module).")
  );
  return system_settings_form($form);
}
