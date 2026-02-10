package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.hardware.Camera;

/**
 * KEPCO_RULE_142
 */

public class BadParameterInCameraParametersSetFlashMode {
    public void tester(Camera.Parameters parameters) {
        parameters.setFlashMode(Camera.Parameters.FLASH_MODE_AUTO); // OK
        parameters.setFlashMode(parameters.FLASH_MODE_RED_EYE); // OK
        parameters.setFlashMode("off"); // @violation
        parameters.setFlashMode(Camera.Parameters.FLASH_MODE_TORCH); // OK
        parameters.setFlashMode("test"); // @violation
    }
}
