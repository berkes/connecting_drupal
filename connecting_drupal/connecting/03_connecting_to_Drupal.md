!SLIDE bullets incremental
# Connecting your app to Drupal #
## External &larr;_Pulls from_&larr; Drupal ##
* Menu-handler
* Services

!SLIDE bullets incremental
# Menu-handler #
* Write your own code.
* KISS. (performant, managable, quick and to the point)
* Not at all hard.

!SLIDE code
# Tools #
    @@@ PHP
    hook_menu();
      'acces callback' => check_if_caller_can_use_services();
    drupal_json($matches);
    SimpleXML::asXML

!SLIDE center
# Demo #

!SLIDE bullets incremental
# Services #
* [http://drupal.org/project/services](http://drupal.org/project/services)
* Expose Views, CCK, nodequeues and so on as services.
* Access-control based on various systems. (oAuth, token/key, etceteras)
* Featurefull, complex. (40+K, ~6000+lines)
* Requires writing views-addons, cck-modules or services addons for custom data.

!SLIDE bullets incremental
# Pro and Cons #
* Services offers lots of features.
* Services handles POSTs, DELETEs and PUTs.
* Services has access control.
* Services is complex.

!SLIDE bullets incremental
# Pro and Cons 2 #
* Menu-handler is simple.
* Menu-handler can perform ge-normous.
* Menu-handler makes implementing odd Business Logic dead-easy. 
