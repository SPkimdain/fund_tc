package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.graphics.Paint;

/**
 * KEPCO_RULE_185
 */

public class BadParameterInPaintSetTextSize {
    public void tester(Paint paint) {
        paint.setTextSize(0); // @violation
        paint.setTextSize(10); // OK
        paint.setTextSize(-5.2f); // @violation
        paint.setTextSize(3.4f); // OK
    }
}
