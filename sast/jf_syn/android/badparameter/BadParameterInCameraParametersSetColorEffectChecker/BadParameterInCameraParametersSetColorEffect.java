package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.hardware.Camera;

/**
 * KEPCO_RULE_141
 */

public class BadParameterInCameraParametersSetColorEffect {
    public void tester(Camera.Parameters parameters) {
        parameters.setColorEffect(Camera.Parameters.EFFECT_AQUA); // OK
        parameters.setColorEffect("aqua"); // @violation
        parameters.setColorEffect(Camera.Parameters.EFFECT_MONO); // OK
        parameters.setColorEffect("solarize"); // @violation
        parameters.setColorEffect(Camera.Parameters.EFFECT_SEPIA); // OK
    }
}
