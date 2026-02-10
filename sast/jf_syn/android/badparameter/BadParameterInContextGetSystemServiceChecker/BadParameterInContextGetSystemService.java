package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.app.ActivityManager;
import android.content.Context;

/**
 * KEPCO_RULE_133
 */

public class BadParameterInContextGetSystemService {
    public void tester(Context context) {
        context.getSystemService(Context.LOCATION_SERVICE); // OK
        context.getSystemService(Context.ACCOUNT_SERVICE); // OK
        context.getSystemService(ActivityManager.class); // OK
        context.getSystemService("location"); // @violation
        context.getSystemService("camera"); // @violation
        context.getSystemService(Context.WIFI_SERVICE); // OK
    }
}
