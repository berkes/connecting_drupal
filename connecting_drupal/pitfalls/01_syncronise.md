!SLIDE bullets incremental
# Common pitfalls #
* Synchronisation
* Synchronisation 
* and Synchronisation

!SLIDE bullets incremental
# Avoid Synchronisation # 
* but Cache.
 * GETs can be `cache_set(); cache_get();`-ed.
 * POSTs, PUTs and DELETEs can be queued. Write your own spool-queue (Drupal has no general one).
 
!SLIDE bullets incremental
# Other common pitfalls #
## Drupal has a database abstraction layer, can we not add our services to that? ##
* DBA in Drupal (6) is only a way to allow postgreSQL for the Brave Few.
* DBA in Drupal 7 is a way to abstract SQL databases. Not something non-SQLish.

!SLIDE bullets incremental
# Other common pitfalls #
## Attempting a generalised solution. ##
* Putting stuff into Nodes, Taxonomy, CCK, and Views 
* Requires synchronisation. 
* CCK is tightly coupled to the _relational_ database
* Avoid nodes. 

!SLIDE bullets incremental
# Pitfall: Nodes #
* All content on a Drupal website is **stored** and treated as "nodes." 
* A node is any **posting**, such as a page, poll, story, forum text, or blog entry.

* Stored: Database (synchronisation)
* Postings: Articles (is it an article)

!SLIDE bullets incremental
# Other common pitfalls #
## Running out of IDs. ##
* Don't use Drupal-thingies to store/cache remote-thingies: avoids using keys.
* That also avoids synchronisation.

!SLIDE bullets incremental
# Other common pitfalls #
## Attempt to make Drupal "a thin layer around an app". ##
* Keep things slim, KISS.
* Write your own modules, use it as framework: else it is no "thin layer", but a vast, complex beast. 
* Write your own CMS/APP, dedicated. With Drupalisms (dabr).
