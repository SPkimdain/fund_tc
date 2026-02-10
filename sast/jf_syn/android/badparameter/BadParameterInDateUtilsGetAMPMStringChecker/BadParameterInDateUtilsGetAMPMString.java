package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.text.format.DateUtils;

import java.util.Calendar;

/**
 * KEPCO_RULE_158
 */

public class BadParameterInDateUtilsGetAMPMString {
    public void tester() {
        DateUtils.getAMPMString(Calendar.AM); // OK
        DateUtils.getAMPMString(Calendar.PM); // OK
        DateUtils.getAMPMString(0); // @violation
        DateUtils.getAMPMString(1); // @violation
        DateUtils.getAMPMString(-1); // @violation
    }
}
