A live sample page can be seen at http://drupal.adaptivethemes.com

Installation and basic configuration:

  1. Download Newswire theme from http://drupal.org/project/newswire

  2. Unpack the downloaded file, take the entire newswire folder (which includes
     the README.txt file and all the themes files) and place it in your
     Drupal installation under one of the following locations:
       sites/all/themes
         making it available to the default Drupal site and to all Drupal sites
         in a multi-site configuration
       sites/default/themes
         making it available to only the default Drupal site
       sites/example.com/themes
         making it available to only the example.com site if there is a
         sites/example.com/settings.php configuration file

  3. Log in as an administrator on your Drupal site and go to Administer > Site
     building > Themes (admin/build/themes) and make newswire the default theme.
	 
  4. Theme Settings.
  
     Go to Administer > Site building > Themes > Configure > Newswire 
     (admin/build/themes/settings/newswire) and configure settings for the 
	   newswire theme. 
	 
	   All features are supported but you can only display a logo OR the site name. 
	   If the logo is checked, newswire will display the logo - you must uncheck 
	   logo to display the site name in the header.
	 
	   SETTING YOUR DEFAULT STYLESHEET
	   On the theme settings page, scroll to the bottom and you will see a new drop
	   menu - select your desired theme style sheet and save your settings.
	 
	   CUSTOMISING THE CUSTOM STYLESHEETS
	   There are two style sheets to you can customise to make your own theme,
	   newswire_custom-gray.css and newswire_custom-tan.css. 
	 
	   The custom stylesheets are located in the /css/ folder in the Newswire 
	   theme directory.
	 
	   The Gray theme has gray blocks, tables and highlights and the Tan has tan 
	   blocks, tables	 and highlights. Follow the instructions at the top of 
	   the style sheet (bascially seach and replace colors as per the instructions). 
	   This will modify all the necessary colours including the Suckefish drop menus.

  5. Blocks.
  
     Go to Administer > Site building > Blocks (admin/build/block/list/newswire)
     and configure your block settings.
	 
	   Newswire has 4 columns and multiple additional regions - see the main screen shot 
	   at http://drupal.org/project/newswire for a visual overview of all the regions.
	 
	   A region will only become active if a block is placed within it, this includes the
	   3 sidebars - Left, Right_2 (inside right) and Right.
		 
		 NOTE: The regions "Right top box" & "Right bottom box" can only be active IF both the
		 Right and Right_2 regions are also active.
	 
  6. Default Avatar.
  
     If you would like to use the anonymous users avatar supplied with the theme,
     go to User management > User setting (admin/user/settings), enable pictures
	   for users and paste in the path "sites/all/themes/newswire/images/avatar.png".
	   Modify the path if you have installed newswire in a different directory. 
	 
	   Newswire is designed to support user pictures/avatars of the default size 
	   (85x85px), if you change this you may need to modify the CSS in styles.css 
	   line ~479 e.g.
	 
	   div.comment-content.with-picture {
         margin-left: 95px; /* modify the margin as requried */
       }
	   
  7. Suckerfish Drop Menus. 
  
     The first thing you must do is disable Primary links
     in the theme settings. If you don't your menu won't show up.
  
     Create your menu with the standard Drupal menu system. Make sure all menu 
	   entries are set to "expanded". Place the menu block in the Suckerfish region, be 
	   sure to set the block title as <none>. The menu will automagically become a drop
	   menu.
	 

  8. Customizing the Layout.

     Newswire is built on top of a flexible theme framework. You should study the CSS,
     in particular layout.css, layout-DEV.css, page.tpl.php and template.php.
	 
	   layout-DEV.css is the full theme framework, while the layout.css is just a subset 
	   that is actually used by Newswire.

     Please contact jeff [att] adaptivethemes [a.dot] com is you would like to hire me
	   for your customizations.

     
Found a bug or need support?

Please visit the project page and post it in the issue queue.
http://drupal.org/project/newswire
