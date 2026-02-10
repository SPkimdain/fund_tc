package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.hardware.Sensor;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Handler;

/**
 * KEPCO_RULE_144
 */

public class BadParameterInSensorManagerRegisterListener {
    public void tester(SensorManager manager, SensorEventListener listener, Sensor sensor, int maxReportLatencyUs, Handler handler) {
        manager.registerListener(listener, sensor, 0); // @violation
        manager.registerListener(listener, sensor, SensorManager.SENSOR_DELAY_NORMAL); // OK
        manager.registerListener(listener, sensor, 2, maxReportLatencyUs); // @violation
        manager.registerListener(listener, sensor, SensorManager.SENSOR_DELAY_UI, maxReportLatencyUs); // OK
        manager.registerListener(listener, sensor, 5, handler); // @violation
        manager.registerListener(listener, sensor, SensorManager.SENSOR_DELAY_GAME, handler); // OK
        manager.registerListener(listener, sensor, 10, maxReportLatencyUs, handler); // @violation
        manager.registerListener(listener, sensor, SensorManager.SENSOR_DELAY_FASTEST, maxReportLatencyUs, handler); // OK
    }
}
