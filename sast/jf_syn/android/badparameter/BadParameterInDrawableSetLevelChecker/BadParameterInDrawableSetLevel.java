package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.graphics.drawable.Drawable;

/**
 * KEPCO_RULE_194
 */

public class BadParameterInDrawableSetLevel {
    public void tester(Drawable drawable) {
        drawable.setLevel(0); // OK
        drawable.setLevel(10000); // OK
        drawable.setLevel(10001); // @violation
        drawable.setLevel(-1); // @violation
        drawable.setLevel(100); // OK
    }
}
