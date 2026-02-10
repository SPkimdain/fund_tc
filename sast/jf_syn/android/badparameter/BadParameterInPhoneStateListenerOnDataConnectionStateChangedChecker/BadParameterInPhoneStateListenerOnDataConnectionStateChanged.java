package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.telephony.PhoneStateListener;
import android.telephony.TelephonyManager;

/**
 * KEPCO_RULE_155
 */

public class BadParameterInPhoneStateListenerOnDataConnectionStateChanged {
    public void tester(PhoneStateListener listener, int networkType) {
        listener.onDataConnectionStateChanged(0); // @violation
        listener.onDataConnectionStateChanged(TelephonyManager.DATA_CONNECTED, networkType); // OK
        listener.onDataConnectionStateChanged(TelephonyManager.DATA_CONNECTING); // OK
        listener.onDataConnectionStateChanged(TelephonyManager.DATA_ACTIVITY_DORMANT, networkType); // @violation
        listener.onDataConnectionStateChanged(TelephonyManager.DATA_DISCONNECTED, networkType); // OK
    }
}
