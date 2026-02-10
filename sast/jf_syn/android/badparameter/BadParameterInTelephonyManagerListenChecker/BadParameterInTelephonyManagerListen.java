package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.telephony.PhoneStateListener;
import android.telephony.TelephonyManager;

/**
 * KEPCO_RULE_156
 */

public class BadParameterInTelephonyManagerListen {
    public void tester(TelephonyManager manager, PhoneStateListener listener) {
        manager.listen(listener, PhoneStateListener.LISTEN_CALL_FORWARDING_INDICATOR); // OK
        manager.listen(listener, 1); // @violation
        manager.listen(listener, PhoneStateListener.LISTEN_SERVICE_STATE); // OK
        manager.listen(listener, PhoneStateListener.LISTEN_MESSAGE_WAITING_INDICATOR); // OK
        manager.listen(listener, 5); // @violation
    }

}
