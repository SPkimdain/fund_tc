package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.app.Activity;
import android.content.Intent;
import android.content.IntentSender;
import android.os.Bundle;

/**
 * KEPCO_RULE_203
 */

public class BadParameterInActivityStartIntentSender {
    public void tester(Activity act, IntentSender intent, Intent fillInIntent, int flagMask, int flagValues, Bundle options) {
        try {
            act.startIntentSender(intent, fillInIntent, flagMask, flagValues, 0); // OK
            act.startIntentSender(intent, fillInIntent, flagMask, flagValues, 0, options); // OK
            act.startIntentSender(intent, fillInIntent, flagMask, flagValues, 2); // @violation
            act.startIntentSender(intent, fillInIntent, flagMask, flagValues, -1, options); // @violation
        } catch (IntentSender.SendIntentException e) {
        }
    }
}
