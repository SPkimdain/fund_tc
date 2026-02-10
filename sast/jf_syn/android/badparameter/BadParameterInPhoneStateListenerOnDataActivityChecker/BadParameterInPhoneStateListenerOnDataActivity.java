package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.telephony.PhoneStateListener;
import android.telephony.TelephonyManager;

/**
 * KEPCO_RULE_154
 */

public class BadParameterInPhoneStateListenerOnDataActivity {
    public void tester(PhoneStateListener listener) {
        listener.onDataActivity(0); // @violation
        listener.onDataActivity(TelephonyManager.DATA_ACTIVITY_INOUT); // OK
        listener.onDataActivity(TelephonyManager.DATA_ACTIVITY_IN); // OK
        listener.onDataActivity(TelephonyManager.DATA_ACTIVITY_NONE); // OK
        listener.onDataActivity(TelephonyManager.DATA_CONNECTING); // @violation
    }
}
