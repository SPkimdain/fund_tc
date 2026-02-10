package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.text.format.Time;

/**
 * KEPCO_RULE_198
 */

public class BadParameterInTimeSetMonthDay {
    public void tester(Time time, int month, int year) {
        time.set(1, month, year); // OK
        time.set(13, month, year); // OK
        time.set(31, month, year); // OK
        time.set(32, month, year); // @violation
        time.set(0, month, year); // @violation
    }
}
