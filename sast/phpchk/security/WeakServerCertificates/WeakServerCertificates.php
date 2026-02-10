<?php
    function violation() {
        curl_setopt($curl, CURLOPT_SSL_VERIFYPEER, FALSE);      // @violation
        curl_setopt($curl, CURLOPT_SSL_VERIFYPEER, false);      // @violation
        curl_setopt($curl, CURLOPT_SSL_VERIFYPEER, 0);          // @violation
    }

    function good() {
        curl_setopt($curl, CURLOPT_SSL_VERIFYPEER, TRUE);       // good
        curl_setopt($curl, CURLOPT_SSL_VERIFYPEER, true);       // good
        curl_setopt($curl, CURLOPT_SSL_VERIFYPEER, 1);          // good
    }


   function violation_array() {
       $ch = curl_init();
       $options = array(CURLOPT_POST              => true,
                        CURLOPT_SSL_VERIFYPEER    => false,
                        CURLOPT_HEADER            => true,
                        CURLOPT_URL               => $url,
                   );
       curl_setopt_array($ch, $options); // @violation
   }

   function violation1() {
   		if ( false ){
   	        $com = curl_init();
   	        curl_setopt( $com, CURLOPT_POST, false );
   	        curl_setopt( $com, CURLOPT_SSL_VERIFYPEER, false );  // @violation
   	        curl_setopt( $com, CURLOPT_SSL_VERIFYHOST, false );
   	        curl_setopt( $com, CURLOPT_RETURNTRANSFER, true );
   	        curl_setopt( $com, CURLOPT_URL, $url );
   	        $res = curl_exec( $com );
   	        $httpCode = curl_getinfo( $com, CURLINFO_HTTP_CODE );
   	    }
   	}
?>