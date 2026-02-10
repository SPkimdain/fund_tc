package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.view.ViewGroup;
import android.widget.GridView;

/**
 * KEPCO_RULE_173
 */

public class BadParameterInViewGroupSetPersistentDrawingCache {
    public void tester(ViewGroup viewGroup, GridView gridView) {
        viewGroup.setPersistentDrawingCache(ViewGroup.PERSISTENT_ALL_CACHES); // OK
        viewGroup.setPersistentDrawingCache(0); // @violation
        gridView.setPersistentDrawingCache(ViewGroup.PERSISTENT_SCROLLING_CACHE); // OK, GridView extends ViewGroup
        gridView.setPersistentDrawingCache(3); // @violation, GridView extends ViewGroup
        viewGroup.setPersistentDrawingCache(ViewGroup.PERSISTENT_ANIMATION_CACHE); // OK
    }
}
