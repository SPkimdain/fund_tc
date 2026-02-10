package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.app.Activity;
import android.content.Context;

/**
 * KEPCO_RULE_162
 */

public class BadParameterInActivityGetPreference {
    public void tester(Activity act) {
        act.getPreferences(Context.MODE_PRIVATE); // OK
        act.getPreferences(Context.MODE_WORLD_READABLE); // OK
        act.getPreferences(100); // @violation
        act.getPreferences(Context.MODE_WORLD_WRITEABLE); // OK
        act.getPreferences(0); // @violation
    }
}