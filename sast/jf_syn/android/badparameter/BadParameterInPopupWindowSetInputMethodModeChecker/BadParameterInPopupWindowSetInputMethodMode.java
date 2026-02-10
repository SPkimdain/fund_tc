package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.widget.PopupWindow;

/**
 * KEPCO_RULE_178
 */

public class BadParameterInPopupWindowSetInputMethodMode {
    public void tester(PopupWindow window) {
        window.setInputMethodMode(PopupWindow.INPUT_METHOD_NEEDED); // OK
        window.setInputMethodMode(10); // @violation
        window.setInputMethodMode(PopupWindow.INPUT_METHOD_NOT_NEEDED); // OK
        window.setInputMethodMode(0); // @violation
        window.setInputMethodMode(PopupWindow.INPUT_METHOD_FROM_FOCUSABLE); // OK
    }
}
