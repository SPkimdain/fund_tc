package com.fasoo.javafinch.syn.checker.android.forbidden;

import android.telephony.TelephonyManager;

/**
 * KEPCO_RULE_207
 */

public class DoNotGetDeviceId {
    public void tester(TelephonyManager manager) {
        manager.getDeviceId(); // @violation
        manager.getPhoneType(); // OK
    }
}
