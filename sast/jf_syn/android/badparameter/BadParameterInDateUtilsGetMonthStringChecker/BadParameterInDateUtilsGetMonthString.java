package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.text.format.DateUtils;

import java.util.Calendar;

/**
 * KEPCO_RULE_160
 */

public class BadParameterInDateUtilsGetMonthString {
    public void tester() {
        DateUtils.getMonthString(Calendar.JANUARY, DateUtils.LENGTH_LONG); // OK
        DateUtils.getMonthString(Calendar.FEBRUARY, DateUtils.LENGTH_SHORT); // OK
        DateUtils.getMonthString(2, DateUtils.LENGTH_SHORT); // @violation
        DateUtils.getMonthString(Calendar.MARCH, 0); // @violation
        DateUtils.getMonthString(Calendar.APRIL, -5); // @violation
    }
}
