package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.text.format.DateUtils;

import java.util.Calendar;

/**
 * KEPCO_RULE_159
 */

public class BadParameterInDateUtilsGetDayOfWeekString {
    public void tester() {
        DateUtils.getDayOfWeekString(Calendar.SUNDAY, DateUtils.LENGTH_LONG); // OK
        DateUtils.getDayOfWeekString(Calendar.MONDAY, DateUtils.LENGTH_SHORT); // OK
        DateUtils.getDayOfWeekString(2, DateUtils.LENGTH_SHORT); // @violation
        DateUtils.getDayOfWeekString(Calendar.WEDNESDAY, 0); // @violation
        DateUtils.getDayOfWeekString(Calendar.THURSDAY, -5); // @violation
        DateUtils.getDayOfWeekString(Calendar.DECEMBER, DateUtils.LENGTH_LONG); // @violation
    }
}
