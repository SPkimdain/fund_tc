package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.graphics.drawable.Drawable;

/**
 * KEPCO_RULE_193
 */

public class BadParameterInDrawableSetAlpha {
    public void tester(Drawable drawable) {
        drawable.setAlpha(0); // OK
        drawable.setAlpha(100); // OK
        drawable.setAlpha(255); // OK
        drawable.setAlpha(-1); // @violation
        drawable.setAlpha(256); // @violation
        drawable.setAlpha(300); // @violation
    }
}
