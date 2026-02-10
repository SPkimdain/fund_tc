package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.content.IntentFilter;

/**
 * KEPCO_RULE_192
 */

public class BadParameterInIntentFilterSetPriority {
    public void tester(IntentFilter filter) {
        filter.setPriority(-1002); // @violation
        filter.setPriority(0); // OK
        filter.setPriority(IntentFilter.SYSTEM_LOW_PRIORITY + 1); // OK
        filter.setPriority(79); // OK
        filter.setPriority(-125); // OK
        filter.setPriority(IntentFilter.SYSTEM_HIGH_PRIORITY - 1); // OK
        filter.setPriority(1200); // @violation
    }
}
