package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.hardware.Camera;

/**
 * KEPCO_RULE_139
 */

public class BadParameterInCameraParametersSetWhiteBalance {
    public void tester(Camera.Parameters parameters) {
        parameters.setWhiteBalance(Camera.Parameters.WHITE_BALANCE_AUTO); // OK
        parameters.setWhiteBalance(Camera.Parameters.SCENE_MODE_AUTO); // @violation
        parameters.setWhiteBalance(Camera.Parameters.WHITE_BALANCE_SHADE); // OK
        parameters.setWhiteBalance("twilight"); // @violation
        parameters.setWhiteBalance(Camera.Parameters.WHITE_BALANCE_FLUORESCENT); // OK
    }
}
