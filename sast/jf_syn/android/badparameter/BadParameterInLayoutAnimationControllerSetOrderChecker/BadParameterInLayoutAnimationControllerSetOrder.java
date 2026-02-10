package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.view.animation.LayoutAnimationController;

/**
 * KEPCO_RULE_176
 */

public class BadParameterInLayoutAnimationControllerSetOrder {
    public void tester(LayoutAnimationController controller) {
        controller.setOrder(LayoutAnimationController.ORDER_NORMAL); // OK
        controller.setOrder(10); // @violation
        controller.setOrder(LayoutAnimationController.ORDER_RANDOM); // OK
        controller.setOrder(0); // @violation
        controller.setOrder(LayoutAnimationController.ORDER_REVERSE); // OK
    }
}
