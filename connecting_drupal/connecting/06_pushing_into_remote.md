!SLIDE bullets incremental
# Pushing data from Drupal into Remote #
* There is a module that (almost) does that. 
* Just run your own code:
 * `hook_form_alter()`, adds a _submit callback_, which pushes data into remote.
* Be carefull with _actions_, often cannot handle errors from remote.
* (_you must_ handle errors from remote, submit-callback is not atomic!)

