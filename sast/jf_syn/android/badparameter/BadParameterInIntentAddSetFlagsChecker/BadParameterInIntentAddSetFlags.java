package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.content.Intent;

/**
 * KEPCO_RULE_132
 */

public class BadParameterInIntentAddSetFlags {
    public void tester(Intent intent) {
        intent.addFlags(100); // @violation
        intent.addFlags(Intent.FLAG_GRANT_READ_URI_PERMISSION); // OK
        intent.addFlags(Intent.FLAG_ACTIVITY_NEW_DOCUMENT); // OK
        intent.setFlags(Intent.FLAG_ACTIVITY_TASK_ON_HOME); // OK
        intent.setFlags(20); // @violation
        intent.setFlags(Intent.FILL_IN_PACKAGE); // @violation
    }
}
