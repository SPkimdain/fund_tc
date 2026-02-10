package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.inputmethodservice.InputMethodService;
import android.view.KeyEvent;

/**
 * KEPCO_RULE_147
 */

public class BadParameterInInputMethodServiceSendDownUpKeyEvents {
    public void tester(InputMethodService service) {
        service.sendDownUpKeyEvents(0); // @violation
        service.sendDownUpKeyEvents(KeyEvent.KEYCODE_0); // OK
        service.sendDownUpKeyEvents(KeyEvent.KEYCODE_2); // OK
        service.sendDownUpKeyEvents(KeyEvent.ACTION_UP); // @violation
        service.sendDownUpKeyEvents(KeyEvent.FLAG_LONG_PRESS); // @violation
        service.sendDownUpKeyEvents(KeyEvent.KEYCODE_A); // OK
        service.sendDownUpKeyEvents(96); // @violation
    }
}
