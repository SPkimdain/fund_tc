package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.telephony.PhoneStateListener;
import android.telephony.TelephonyManager;

/**
 * KEPCO_RULE_153
 */

public class BadParameterInPhoneStateListenerOnCallStateChanged {
    public void tester(PhoneStateListener listener, String incomingNumber) {
        listener.onCallStateChanged(TelephonyManager.CALL_STATE_RINGING, incomingNumber); // OK
        listener.onCallStateChanged(0, incomingNumber); // @violation
        listener.onCallStateChanged(TelephonyManager.CALL_STATE_OFFHOOK, incomingNumber); // OK
        listener.onCallStateChanged(4, incomingNumber); // @violation
        listener.onCallStateChanged(TelephonyManager.CALL_STATE_IDLE, incomingNumber); // OK
    }
}
