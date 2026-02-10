package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.hardware.SensorManager;

/**
 * KEPCO_RULE_145
 */

public class BadParameterInSensorManagerRemapCoordinateSystem {
    public void tester(float[] inR, float[] outR) {
        SensorManager.remapCoordinateSystem(inR, 0, 0, outR); // @violation 2
        SensorManager.remapCoordinateSystem(inR, SensorManager.AXIS_X, SensorManager.AXIS_Y, outR); // OK
        SensorManager.remapCoordinateSystem(inR, SensorManager.AXIS_X, 2, outR); // @violation
        SensorManager.remapCoordinateSystem(inR, SensorManager.AXIS_MINUS_X, SensorManager.AXIS_Z, outR); // OK
        SensorManager.remapCoordinateSystem(inR, SensorManager.AXIS_MINUS_Z, SensorManager.AXIS_MINUS_Y, outR); // OK
        SensorManager.remapCoordinateSystem(inR, 3, SensorManager.AXIS_MINUS_Y, outR); // @violation
    }
}
