package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.location.Geocoder;

import java.io.IOException;

/**
 * KEPCO_RULE_195
 */

public class BadParameterInGeocoderGetFromLocationLatitude {
    public void tester(Geocoder geocoder, double longitude, int maxResults) {
        try {
            geocoder.getFromLocation(-90, longitude, maxResults); // OK
            geocoder.getFromLocation(90, longitude, maxResults); // OK
            geocoder.getFromLocation(85.5, longitude, maxResults); // OK
            geocoder.getFromLocation(90.1, longitude, maxResults); // @violation
            geocoder.getFromLocation(-96, longitude, maxResults); // @violation
        } catch(IOException e) {
        }
    }
}
