package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.location.Geocoder;

import java.io.IOException;

/**
 * KEPCO_RULE_196
 */

public class BadParameterInGeocoderGetFromLocationLongitude {
    public void tester(Geocoder geocoder, double latitude, int maxResults) {
        try {
            geocoder.getFromLocation(latitude, -180, maxResults); // OK
            geocoder.getFromLocation(latitude, 180, maxResults); // OK
            geocoder.getFromLocation(latitude, 170.5, maxResults); // OK
            geocoder.getFromLocation(latitude, 180.1, maxResults); // @violation
            geocoder.getFromLocation(latitude, -188, maxResults); // @violation
        } catch(IOException e) {
        }
    }
}
