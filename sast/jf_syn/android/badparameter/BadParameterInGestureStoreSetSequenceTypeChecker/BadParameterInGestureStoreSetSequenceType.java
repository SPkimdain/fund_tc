package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.gesture.GestureStore;

/**
 * KEPCO_RULE_135
 */

public class BadParameterInGestureStoreSetSequenceType {
    public void tester(GestureStore store) {
        store.setSequenceType(GestureStore.SEQUENCE_INVARIANT); // OK
        store.setSequenceType(GestureStore.SEQUENCE_SENSITIVE); // OK
        store.setSequenceType(0); // @violation
        store.setSequenceType(-30); // @violation
        store.setSequenceType(2); // @violation
    }
}
