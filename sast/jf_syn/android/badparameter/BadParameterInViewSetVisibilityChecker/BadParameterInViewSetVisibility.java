package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.view.View;

/**
 * KEPCO_RULE_171
 */

public class BadParameterInViewSetVisibility {
    public void tester(View view) {
        view.setVisibility(View.VISIBLE); // OK
        view.setVisibility(View.GONE); // OK
        view.setVisibility(0); // @violation
        view.setVisibility(-2); // @violation
        view.setVisibility(View.SYSTEM_UI_FLAG_VISIBLE); // @violation
    }
}
