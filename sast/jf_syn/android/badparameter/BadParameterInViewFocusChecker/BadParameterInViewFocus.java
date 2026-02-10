package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.content.Context;
import android.graphics.Rect;
import android.view.View;
import android.view.ViewGroup;
import android.webkit.WebView;
import android.widget.GridView;
import android.widget.ZoomButton;

/**
 * KEPCO_RULE_168
 */

public abstract class BadParameterInViewFocus extends ViewGroup {
    public BadParameterInViewFocus(Context context) { super(context); }

    public void tester(View view, Rect previouslyFocusedRect, ViewGroup viewGroup, WebView webView, GridView gridView, ZoomButton button, boolean gainFocus) {
        view.focusSearch(View.FOCUS_DOWN); // OK
        viewGroup.focusSearch(View.FOCUS_LEFT); // OK
        webView.focusSearch(View.FOCUS_RIGHT); // OK
        view.focusSearch(View.FOCUS_FORWARD); // @violation
        view.requestFocus(0, previouslyFocusedRect); // @violation
        viewGroup.requestFocus(View.FOCUS_UP, previouslyFocusedRect); // OK
        gridView.requestFocus(View.FOCUS_BACKWARD, previouslyFocusedRect); // @violation

        onRequestFocusInDescendants(View.FOCUS_UP, previouslyFocusedRect); // OK
        onRequestFocusInDescendants(2, previouslyFocusedRect); // @violation

        onFocusChanged(gainFocus, FOCUS_DOWN, previouslyFocusedRect); // OK
        onFocusChanged(gainFocus, View.FOCUS_LEFT, previouslyFocusedRect); // OK
        onFocusChanged(gainFocus, FOCUS_FORWARD, previouslyFocusedRect); // OK
        onFocusChanged(gainFocus, 3, previouslyFocusedRect); // @violation

        button.dispatchUnhandledMove(view, View.FOCUS_LEFT); // OK
        button.dispatchUnhandledMove(webView, FOCUS_RIGHT); // OK
        button.dispatchUnhandledMove(gridView, -1); // @violation
    }
}
