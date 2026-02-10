package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.view.VelocityTracker;

/**
 * KEPCO_RULE_190
 */

public class BadParameterInVelocityTrackerComputeCurrentVelocity {
    public void tester(VelocityTracker tracker, int units) {
        tracker.computeCurrentVelocity(units, 0); // @violation
        tracker.computeCurrentVelocity(units, 1); // OK
        tracker.computeCurrentVelocity(units, 123); // OK
        tracker.computeCurrentVelocity(units, -1); // @violation
    }
}
