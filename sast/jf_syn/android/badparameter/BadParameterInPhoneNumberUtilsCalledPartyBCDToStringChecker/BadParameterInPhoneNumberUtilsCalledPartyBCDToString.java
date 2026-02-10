package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.telephony.PhoneNumberUtils;

/**
 * KEPCO_RULE_188
 */

public class BadParameterInPhoneNumberUtilsCalledPartyBCDToString {
    public void tester(byte[] bytes, int offset) {
        PhoneNumberUtils.calledPartyBCDToString(bytes, offset, 0); // @violation
        PhoneNumberUtils.calledPartyBCDToString(bytes, offset, 1); // @violation
        PhoneNumberUtils.calledPartyBCDToString(bytes, offset, 2); // OK
        PhoneNumberUtils.calledPartyBCDToString(bytes, offset, 10); // OK
    }
}
