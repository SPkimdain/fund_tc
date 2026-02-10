package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.view.View;
import android.view.ViewGroup;
import android.webkit.WebView;

/**
 * KEPCO_RULE_169
 */

public class BadParameterInViewSetDrawingCacheQuality {
    public void tester(View view, ViewGroup viewGroup, WebView webView) {
        view.setDrawingCacheQuality(0); // @violation
        view.setDrawingCacheQuality(View.DRAWING_CACHE_QUALITY_HIGH); // OK
        viewGroup.setDrawingCacheQuality(2); // @violation, ViewGroup extends View
        viewGroup.setDrawingCacheQuality(View.DRAWING_CACHE_QUALITY_AUTO); // OK, ViewGroup extends View
        webView.setDrawingCacheQuality(View.DRAWING_CACHE_QUALITY_LOW); // OK, WebView extends View
        webView.setDrawingCacheQuality(3); // @violation, WebView extends View
    }
}
