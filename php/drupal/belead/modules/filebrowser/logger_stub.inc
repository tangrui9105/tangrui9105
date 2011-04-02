<?php


/* This file is part of "logger".
 *    Copyright 2009, arNuméral
 *    Author : Yoran Brault
 *    eMail  : yoran.brault@bad_arnumeral.fr (remove bad_ before sending an email)
 *    Site   : http://www.arnumeral.fr/node/5
 *
 * "logger" is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * "logger" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with "Broken Anchor for Node comments Module"; if not, write to the Free
 * Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA, or see the FSF site: http://www.fsf.org.
 */

if (module_exists("logger")) {
	require_once (drupal_get_path("module", "logger") . "/logger.inc");
} else {
	if (!function_exists("logger_trace")) {
		function logger_trace($level, $prefix, $message) {
		}
	}
	if (!function_exists("logger_error")) {
		function logger_error($prefix, $message) {
		}
	}

	if (!function_exists("logger_warning")) {
		function logger_warning($prefix, $message) {
		}
	}

	if (!function_exists("logger_debug")) {
		function logger_debug($prefix, $message) {
		}
	}

	if (!function_exists("logger_info")) {
		function logger_info($prefix, $message) {
		}
	}

	if (!function_exists("logger_is_debug")) {
		function logger_is_debug() {
			return false;
		}
	}

	if (!function_exists("logger_is_info")) {
		function logger_is_info() {
			return false;
		}
	}
}