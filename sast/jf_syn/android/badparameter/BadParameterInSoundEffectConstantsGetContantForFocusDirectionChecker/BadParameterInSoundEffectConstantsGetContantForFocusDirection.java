package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.view.SoundEffectConstants;
import android.view.View;

/**
 * KEPCO_RULE_167
 */

public class BadParameterInSoundEffectConstantsGetContantForFocusDirection {
    public void tester(SoundEffectConstants constants)  {
        SoundEffectConstants.getContantForFocusDirection(0); // @violation
        SoundEffectConstants.getContantForFocusDirection(View.FOCUS_UP); // OK
        SoundEffectConstants.getContantForFocusDirection(2); // @violation
        SoundEffectConstants.getContantForFocusDirection(View.FOCUS_FORWARD); // OK
        SoundEffectConstants.getContantForFocusDirection(View.FOCUS_LEFT); // OK
        SoundEffectConstants.getContantForFocusDirection(View.FOCUSABLES_TOUCH_MODE); // @violation
    }
}
