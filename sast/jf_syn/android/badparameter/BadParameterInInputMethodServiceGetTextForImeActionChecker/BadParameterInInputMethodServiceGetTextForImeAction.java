package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.inputmethodservice.InputMethodService;
import android.view.inputmethod.EditorInfo;

/**
 * KEPCO_RULE_146
 */

public class BadParameterInInputMethodServiceGetTextForImeAction {
    public void tester(InputMethodService service) {
        service.getTextForImeAction(0); // @violation
        service.getTextForImeAction(EditorInfo.IME_FLAG_NO_EXTRACT_UI); // OK
        service.getTextForImeAction(3); // @violation
        service.getTextForImeAction(EditorInfo.IME_FLAG_NAVIGATE_NEXT); // OK
        service.getTextForImeAction(EditorInfo.IME_MASK_ACTION); // OK
    }
}
