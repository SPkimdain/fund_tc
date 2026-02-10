package com.fasoo.javafinch.syn.checker.android.forbidden;

import android.telephony.TelephonyManager;

/**
 * KEPCO_RULE_210
 */

public class DoNotGetUsimUniqueId {
    public void tester(TelephonyManager manager) {
        manager.getSubscriberId(); // @violation
        manager.getCallState(); // OK
        manager.getSimSerialNumber(); // @violation
        manager.getDataNetworkType(); // OK
    }
}
