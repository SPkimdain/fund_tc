package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.location.GpsStatus;

/**
 * KEPCO_RULE_148
 */

public class BadParameterInGpsStatusListenerOnGpsStatusChanged {
    public void tester(GpsStatus.Listener listener) {
        listener.onGpsStatusChanged(GpsStatus.GPS_EVENT_FIRST_FIX); // OK
        listener.onGpsStatusChanged(GpsStatus.GPS_EVENT_STARTED); // OK
        listener.onGpsStatusChanged(0); // @violation
        listener.onGpsStatusChanged(GpsStatus.GPS_EVENT_STOPPED); // OK
        listener.onGpsStatusChanged(3); // @violation
    }
}
