package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.location.Address;

/**
 * KEPCO_RULE_189
 */

public class BadParameterInAddressAddressLine {
    public void tester(Address addr, String line) {
        addr.getAddressLine(0); // OK
        addr.getAddressLine(10); // OK
        addr.getAddressLine(-1); // @violation
        addr.setAddressLine(0, line); // OK
        addr.setAddressLine(5, line); // OK
        addr.setAddressLine(-2, line); // @violation
    }
}
