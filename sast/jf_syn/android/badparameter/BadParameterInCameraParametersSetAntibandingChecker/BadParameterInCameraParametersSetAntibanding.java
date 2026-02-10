package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.hardware.Camera;

/**
 * KEPCO_RULE_140
 */

public class BadParameterInCameraParametersSetAntibanding {
    public void tester(Camera.Parameters parameters) {
        parameters.setAntibanding(Camera.Parameters.ANTIBANDING_50HZ); // OK
        parameters.setAntibanding("50hz"); // @violation
        parameters.setAntibanding(Camera.Parameters.ANTIBANDING_AUTO); // OK
        parameters.setAntibanding("off"); // @violation
    }
}
