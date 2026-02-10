package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.location.Location;

/**
 * KEPCO_RULE_151
 */

public class BadParameterInLocationConvertOutputType {
    public void tester() {
        Location.convert(20, Location.FORMAT_DEGREES); // OK
        Location.convert(50, Location.FORMAT_SECONDS); // OK
        Location.convert(-150.0, 0); // @violation
        Location.convert(170.2, 2); // @violation
        Location.convert(-35, Location.FORMAT_MINUTES); // OK
    }
}
