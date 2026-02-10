package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.text.method.MetaKeyKeyListener;
import android.view.KeyEvent;

/**
 * KEPCO_RULE_161
 */

public class BadParameterInMetaKeyKeyListenerGetMetaState {
    public void tester(long state, CharSequence text, KeyEvent event) {
        MetaKeyKeyListener.getMetaState(state, MetaKeyKeyListener.META_SHIFT_ON); // OK
        MetaKeyKeyListener.getMetaState(text, MetaKeyKeyListener.META_SYM_ON); // OK
        MetaKeyKeyListener.getMetaState(text, 0); // @violation
        MetaKeyKeyListener.getMetaState(state, 1); // @violation
        MetaKeyKeyListener.getMetaState(text, MetaKeyKeyListener.META_ALT_ON, event); // OK
    }
}
