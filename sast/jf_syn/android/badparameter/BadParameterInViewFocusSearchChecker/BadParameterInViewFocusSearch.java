package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.view.View;

/**
 * KEPCO_RULE_127
 */

public class BadParameterInViewFocusSearch {
    public void tester(View view) {
        view.focusSearch(View.FOCUS_UP); // OK
        view.focusSearch(0); // @violation
        view.focusSearch(View.FOCUS_DOWN); // OK
        view.focusSearch(2); // @violation
        view.focusSearch(View.FOCUS_LEFT); // OK
        view.focusSearch(3); // @violation
        view.focusSearch(View.FOCUS_RIGHT); // OK
    }
}
