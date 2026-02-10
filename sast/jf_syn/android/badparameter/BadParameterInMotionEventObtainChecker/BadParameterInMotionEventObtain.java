package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.view.MotionEvent;

/**
 * KEPCO_RULE_166
 */

public class BadParameterInMotionEventObtain {
    float x;
    float y;
    long downTime;
    long eventTime;
    int metaState;
    int pointerCount;
    float pressure;
    float size;
    float xPrecision;
    float yPrecision;
    int deviceId;
    int edgeFlags;
    int[] pointerIds;
    MotionEvent.PointerCoords[] pointerCoords;
    MotionEvent.PointerProperties[] pointerProperties;
    int source;
    int flags;
    int buttonState;


    public void tester() {
        MotionEvent.obtain(downTime, eventTime, MotionEvent.ACTION_DOWN, x, y, metaState); // OK
        MotionEvent.obtain(downTime, eventTime, 0, x, y, metaState); // @violation
        MotionEvent.obtain(downTime, eventTime, MotionEvent.ACTION_UP, pointerCount, x, y, pressure, size, metaState, xPrecision, yPrecision, deviceId, edgeFlags); // OK
        MotionEvent.obtain(downTime, eventTime, 1, pointerCount, x, y, pressure, size, metaState, xPrecision, yPrecision, deviceId, edgeFlags); // @violation 2
        MotionEvent.obtain(downTime, eventTime, MotionEvent.ACTION_MOVE, pointerCount, pointerIds, pointerCoords, metaState, xPrecision, yPrecision, deviceId, edgeFlags, source, flags); // OK
        MotionEvent.obtain(downTime, eventTime, 2, pointerCount, pointerProperties, pointerCoords, metaState, buttonState, xPrecision, yPrecision, deviceId, edgeFlags, source, flags); // @violation
        MotionEvent.obtain(downTime, eventTime, MotionEvent.ACTION_DOWN, x, y, pressure, size, metaState, xPrecision, yPrecision, deviceId, edgeFlags); // OK
    }
}
