package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.text.format.Time;

/**
 * KEPCO_RULE_199
 */

public class BadParameterInTimeSetMonth {
    public void tester(Time time, int monthDay, int year) {
        time.set(monthDay, 0, year); // OK
        time.set(monthDay, 2, year); // OK
        time.set(monthDay, 11, year); // OK
        time.set(monthDay, 12, year); // @violation
        time.set(monthDay, -1, year); // @violation
    }
}
