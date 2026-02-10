package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.view.animation.Animation;

/**
 * KEPCO_RULE_174
 */

public class BadParameterInAnimationResolveSize extends Animation {
    public void tester(float value, int size, int parentSize) {
        resolveSize(ABSOLUTE, value, size, parentSize); // OK
        resolveSize(0, value, size, parentSize); // @violation
        resolveSize(RELATIVE_TO_PARENT, value, size, parentSize); // OK
        resolveSize(-3, value, size, parentSize); // @violation
        resolveSize(RELATIVE_TO_SELF, value, size, parentSize); // OK
        resolveSize(5, value, size, parentSize); // @violation
    }
}
