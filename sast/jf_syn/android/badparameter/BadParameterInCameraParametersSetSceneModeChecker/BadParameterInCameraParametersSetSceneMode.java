package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.hardware.Camera;

/**
 * KEPCO_RULE_138
 */

public class BadParameterInCameraParametersSetSceneMode {
    public void tester(Camera.Parameters parameters) {
        parameters.setSceneMode(Camera.Parameters.SCENE_MODE_AUTO); // OK
        parameters.setSceneMode(Camera.Parameters.SCENE_MODE_CANDLELIGHT); // OK
        parameters.setSceneMode(Camera.Parameters.FLASH_MODE_AUTO); // @violation
        parameters.setSceneMode("auto"); // @violation
        parameters.setSceneMode(Camera.Parameters.SCENE_MODE_NIGHT); // OK
    }
}
