package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.location.LocationListener;
import android.location.LocationProvider;
import android.os.Bundle;

/**
 * KEPCO_RULE_149
 */

public class BadParameterInLocationListenerOnStatusChanged {
    public void tester(LocationListener listener, String provider, Bundle extras) {
        listener.onStatusChanged(provider, LocationProvider.OUT_OF_SERVICE, extras); // OK
        listener.onStatusChanged(provider, 0, extras); // @violation
        listener.onStatusChanged(provider, LocationProvider.AVAILABLE, extras); // OK
        listener.onStatusChanged(provider, 2, extras); // @violation
        listener.onStatusChanged(provider, LocationProvider.TEMPORARILY_UNAVAILABLE, extras); // OK
    }
}
