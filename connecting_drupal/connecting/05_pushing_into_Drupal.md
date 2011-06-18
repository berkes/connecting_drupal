!SLIDE bullets incremental
# Connecting your app to Drupal #
## External _Pushes into_ Drupal ##
* _CRUD_: Create, Read, Update, Delete.
* _GET_, aka Read, was covered in menu-router.
* PUT and DELETE are not covered in Drupal other then _same as GET_.
* POST is handled by FormAPI. We don't want forms. 

!SLIDE bullets incremental
# You are on your own #
* hook_menu(), with POST, PUT and DELETE handling in menu-callback. 
* Validate: custom.
* Forgery and Bot-protection: custom.
* Data handling and processing: custom.
* Sorry, "bad luck" with Drupal.

!SLIDE bullets incremental
# Bad luck? #
* As in: it won't help you.
* But it won't (probably) annoy you either.

!SLIDE bullets incremental
# Alternative: Services #
* Offers POST handling.
* In REST mode, handles DELETEs and PUTs.
* Allows writing Services resources.

