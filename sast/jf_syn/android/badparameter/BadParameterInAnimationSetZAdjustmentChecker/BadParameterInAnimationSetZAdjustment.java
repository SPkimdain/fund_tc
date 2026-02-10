package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.view.animation.Animation;

/**
 * KEPCO_RULE_175
 */

public class BadParameterInAnimationSetZAdjustment {
    public void tester(Animation animation) {
        animation.setZAdjustment(5); // @violation
        animation.setZAdjustment(Animation.ZORDER_NORMAL); // OK
        animation.setZAdjustment(Animation.ZORDER_TOP); // OK
        animation.setZAdjustment(-10); // @violation
        animation.setZAdjustment(Animation.ZORDER_BOTTOM); // OK
    }
}
