package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.view.animation.Animation;

/**
 * KEPCO_RULE_129
 */

public class BadParameterInAnimationSetRepeatMode {
    public void tester(Animation animation) {
        animation.setRepeatMode(0); // @violation
        animation.setRepeatMode(Animation.RESTART); // OK
        animation.setRepeatMode(100); // @violation
        animation.setRepeatMode(Animation.REVERSE); // OK
    }
}
