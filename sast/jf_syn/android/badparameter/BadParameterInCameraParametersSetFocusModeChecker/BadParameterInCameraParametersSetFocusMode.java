package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.hardware.Camera;

/**
 * KEPCO_RULE_143
 */

public class BadParameterInCameraParametersSetFocusMode {
    public void tester(Camera.Parameters parameters) {
        parameters.setFocusMode(Camera.Parameters.FOCUS_MODE_AUTO); // OK
        parameters.setFocusMode("auto"); // @violation
        parameters.setFocusMode(parameters.FOCUS_MODE_EDOF); // OK
        parameters.setFocusMode(Camera.Parameters.FOCUS_MODE_INFINITY); // OK
        parameters.setFocusMode(Camera.Parameters.FLASH_MODE_AUTO); // @violation
    }
}
