package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.view.View;

/**
 * KEPCO_RULE_170
 */

public class BadParameterInViewSetScrollBarStyle {
    public void tester(View view) {
        view.setScrollBarStyle(0); // @violation
        view.setScrollBarStyle(View.SCROLLBARS_INSIDE_INSET); // OK
        view.setScrollBarStyle(View.SCROLLBARS_OUTSIDE_INSET); // OK
        view.setScrollBarStyle(3); // @violation
        view.setScrollBarStyle(View.SCROLLBAR_POSITION_DEFAULT); // @violation
    }
}
