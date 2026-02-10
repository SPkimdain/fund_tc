package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.location.Location;

/**
 * KEPCO_RULE_197
 */

public class BadParameterInLocationConvertCoordinate {
    public void tester(int outputType) {
        Location.convert(0, outputType); // OK
        Location.convert(10.5, outputType); // OK
        Location.convert(-190, outputType); // @violation
        Location.convert(180.0, outputType); // OK
        Location.convert(-180, outputType); // OK
        Location.convert(180.05, outputType); // @violation
    }
}
