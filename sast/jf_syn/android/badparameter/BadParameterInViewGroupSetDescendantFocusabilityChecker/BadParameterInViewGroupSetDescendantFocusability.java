package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.view.ViewGroup;
import android.webkit.WebView;

/**
 * KEPCO_RULE_172
 */

public class BadParameterInViewGroupSetDescendantFocusability {
    public void tester(ViewGroup viewGroup, WebView webView) {
        viewGroup.setDescendantFocusability(ViewGroup.FOCUS_AFTER_DESCENDANTS); // OK
        webView.setDescendantFocusability(ViewGroup.FOCUS_BEFORE_DESCENDANTS); // OK, WebView extends ViewGroup
        webView.setDescendantFocusability(2); // @violation, WebView extends ViewGroup
        viewGroup.setDescendantFocusability(ViewGroup.FOCUS_BLOCK_DESCENDANTS); // OK
        viewGroup.setDescendantFocusability(ViewGroup.FOCUS_DOWN); // @violation
    }
}
