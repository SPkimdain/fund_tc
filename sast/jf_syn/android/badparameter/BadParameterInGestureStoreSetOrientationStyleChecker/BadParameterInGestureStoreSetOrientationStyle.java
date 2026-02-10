package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.gesture.GestureStore;

/**
 * KEPCO_RULE_134
 */

public class BadParameterInGestureStoreSetOrientationStyle {
    public void tester(GestureStore store) {
        store.setOrientationStyle(GestureStore.ORIENTATION_INVARIANT); // OK
        store.setOrientationStyle(GestureStore.ORIENTATION_SENSITIVE); // OK
        store.setOrientationStyle(0); // @violation
        store.setOrientationStyle(-5); // @violation
        store.setOrientationStyle(20); // @violation
    }
}
