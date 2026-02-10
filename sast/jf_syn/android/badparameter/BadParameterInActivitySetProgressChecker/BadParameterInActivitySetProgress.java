package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.app.Activity;

/**
 * KEPCO_RULE_200
 */

public class BadParameterInActivitySetProgress {
    public void tester(Activity act) {
        act.setProgress(-1); // @violation
        act.setProgress(500); // OK
        act.setProgress(10000); // OK
        act.setProgress(10001); // @violation

    }
}
