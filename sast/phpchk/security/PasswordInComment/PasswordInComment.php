<?php
  /* password : a!2@3b4a */ // @violation
  /* 비밀번호 : a!2@3b4a */ // @violation
  /* password : a!2@3b4 (SAFE since not a password format) */
  /* password : a12b3cd5 (SAFE since not a password format) */
  $var = 0;

  /* password : 1 */
  /* Key : 94jgk398DSod305jdDGFIO39DJ934mjnKDNGIE34 : Bug key length is 40 */ // @violation
  /* Key : 94jgk398DSod305jdDGFIO39DJ934mjnKDNGIE34dDJ : Safe key length is over 40 */
  /* Key : 94jgk398DSod305jdDGFIO39DJ934mjnKDNG : Safe key length is under 40 */

  $var = $var + 1; // Single line

  function temp($param) {
    // This is a password : a!2@3b4a // @violation
    // This is not a password : aa !2@3 b4a (SAFE since not a password format)
    /* password : a1#cd5 (SAFE since not a password format) */
    /* password : a1d5 (SAFE since not a password format) */
    /* password : a#5 (SAFE since not a password format) */
    return $param + 1;
  }
?>
