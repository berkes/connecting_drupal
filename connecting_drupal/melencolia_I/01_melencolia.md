!SLIDE center
![Melencolia I](./Melencolia_I.jpg)

!SLIDE bullets incremental
#Melencolia# 
* A (really) simple mapper.
* A (really) simple reducer.
* Not to be confused with Map/Reduce

!SLIDE bullets incremental
#Melencolia# 
* Each field can be included
* Each field can be processed _(Busyness Logic)_
* Each field can be combined

!SLIDE code small
# Example #
    @@@PHP
     function _ub_search_api_metafilter_filters() {
      $filter = array(
        'price' => array(
          'name'     => t('Price'),
          'callback' => 
                '_ub_search_api_metafilter_format_price',
        ),
      );

      return $filter;
    }

!SLIDE code small
    @@@PHP
    /**
     * Callback formatter for "price" fields
     *
     * @param $value
     *   Description of param $value
     *
     * @return
     *   Description of return value
     */
    function _ub_search_api_metafilter_format_price($value) {
      if ($value == 0 | (int)$value == 0) {
        return t('free');
      }
      else {
        $price = sprintf('%.2f', $value);
        return t('€ %price', array('%price' => $price));
      }
    }

!SLIDE code small
# Example "Just include" #
    @@@PHP
    'genre' => array(
      'name' => t('Genre or Sort'),
    ),

!SLIDE code small
# Example "Callback: any function" #        
    @@@PHP
    'aantal_zitplaatsen' => array(
      'name' => t('Seats'),
      'callback' => 'intval', // It is perfectly fine to 
                              // define callbacks that 
                              // are core PHP functions. 
    ),

!SLIDE code small
# Example "Callback: include extra fields" #    
    @@@PHP
    'title' => array(
      'name' => t('Title'),
      'callback' => '_ub_search_api_metafilter_format_title',
      'callback arguments' => array('datetime-start',
                                 'datetime-end'), 
            //In addition to the $value, you can provide 
            // extra fields to be passed along to the callback.
    ),
