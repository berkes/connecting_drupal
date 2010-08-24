<?php // $Id$
/**
 * Module:      ub_search_api_metafilter
 * Date:        2010-08-11  19:28
 * Author:      ber
 *
 * @file Uitburo Search API filter library.
 *   Each metadata field in the "event" is pulled trough this filter.
 *   Items that do not appear in the filter-list will not be processed. 
 *   The order of the items in the array is the order in wich they will be presented. 
 *   A filter has a "key" and a "value", the key is the exact name of the 
 *   metadata-element, value is iself an array. The value-array contains one or 
 *   two items, the "name", holding the t()-able string that will be used on screen,
 *   and optional a "callback", wich is a function that will be called to format 
 *   the value. 
 *   For example: @code
   $filter = array(
    'price' => array(
      'name'     => t('Price'), 
      'callback' => '_ub_search_api_metafilter_format_price', //This function will be called to render the final value.
    ),
    'genre' => array(
      'name'     => t('Genre or Sort'), //no callback, raw value will be used.
    ),
  );
  
  function _ub_search_api_metafilter_format_price($value) {
    if ($value == 0 | (int)$value == 0) {
      return t('free');
    }
    else {
      $price = sprintf('%.2f', $value);
      return t('€ %price', array('%price' => $price));
    }
  }

 */
 
/**********************************************************************************
 *                            PUBLIC API FUNCTIONS                                *
 **********************************************************************************/
/**
 * Parse a full list of values. Cannot parse herarchical lists (yet). 
 *
 * @param $original_structure
 *  A list of name-value pairs that must be parsed.
 *
 * @return
 *   array with arrays containing name-value pairs, where name is the filter-defined name and value the parsed value.
 */
function ub_search_api_metafilter_process_all($original_structure) {
  $variables = array();
  
  foreach ($original_structure as $key => $value) {
    //var_dump(array($key=>$value));
    list($description, $filtered_value) = ub_search_api_metafilter_process($key, $original_structure);
    if ($filtered_value) {
      $variables[$key] = array(
        'description' => $description,
        'value' => $filtered_value,
      );
    }
  }
  
  return $variables;
}


/**
 * Parses a single item. 
 *
 * @param $name
 *   the key of the item to be parsed. 
 * @param $original_structure.
 *   A list of name-value pairs that must be parsed.
 *
 * @return
 *   array, containing the new name (description) and 
 */
function ub_search_api_metafilter_process($name, $original_structure) {
  $filtered_value = NULL;
  static $filters;
  //if (empty($filters)) {
    $filters = _ub_search_api_metafilter_filters();
  //}
  //If the item does not appear in the filter. Or the item does not appear in the original structure.
  if (!array_key_exists($name, $filters) || !array_key_exists($name, $original_structure)) {
    return $filtered_value;
  }
  else {
    $value = $original_structure[$name];
    $description = $filters[$name]['name'];
    if (($function = $filters[$name]['callback']) && function_exists($function)) {
      $arguments[] = $value;
      if ($filters[$name]['callback arguments']) {
        foreach ($filters[$name]['callback arguments'] as $argument_name) {//Optionally include extra callback arguments.
          $arguments[] = array_key_exists($argument_name, $original_structure) ? $original_structure[$argument_name] : NULL;
        }
      }
      $filtered_value = call_user_func_array($function, $arguments);
    }
  }

  return array($description, $filtered_value);
}

/**********************************************************************************
 *                            The METAFILTER DEFINITIONS                          *
 **********************************************************************************/
/**
 * The filters for the metafilter. 
 *
 * @return
 *   keyed array of filters. See documentation of this file.
 */
function _ub_search_api_metafilter_filters() {
  $filter = array(
    'price' => array(
      'name'     => t('Price'),
      'callback' => '_ub_search_api_metafilter_format_price',
    ),
    'genre' => array(
      'name'     => t('Genre or Sort'), //no callback, raw value will be used.
    ),
    'aantal_zitplaatsen' => array(
      'name' => t('Seats'),
      'callback' => 'intval', //It is erfectly fine to define callbacks that are core PHP functions. 
    ),
    'title' => array(
      'name' => t('Title'),
      'callback' => '_ub_search_api_metafilter_format_title',
      'callback arguments' => array('datetime-start', 'datetime-end'), //In addition to the $value, you can provide 
                                                               // extra fields to be passed along to the callback.
    ),
  );
  
  return $filter;
}

/**
 * Calback formatter for "price" fields
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

/**
 * Calback formatter for "title" fields
 * Example callback that renders a title in the form of 
 *   FooBar at 22-11-1978 untill 01-01-1979
 *
 * @param $value
 *   Description of param $value
 * @param $start_date
 *   Description of param $start_date
 * @param $start_time
 *   Description of param $start_time
 *
 * @return
 *   Description of return value
 */
function _ub_search_api_metafilter_format_title($value, $start_date, $end_date) {
  $title = '';
  if (!empty($value)) {
    $title = check_plain($value);
    if (!empty($start_date)) {
      //Note this t() string concatenation is ugy, should be done in a single t()-ed call with processors.
      $title .= ' ' .  t('at @start_date', array('@start_date' => check_plain($start_date)));
    }
    if (!empty($start_date)) {
      $title .= ' ' . t('untill @end_date', array('@end_date' => check_plain($end_date)));
    }
  }
  
  return $title;
}
/**********************************************************************************
 *                            PRIVATE HELPERS                                     *
 **********************************************************************************/
//This is the place where to put helper-functions that are used inside the callbacks. 
