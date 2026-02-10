package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.content.Context;
import android.text.format.DateUtils;
import java.util.Formatter;

/**
 * KEPCO_RULE_157
 */

public class BadParameterInDateUtilsFormatDateRange {
    public void tester(Context context, Formatter formatter, long startMillis, long endMillis, String timeZone) {
        DateUtils.formatDateRange(context, formatter, startMillis, endMillis, DateUtils.FORMAT_SHOW_TIME); // OK
        DateUtils.formatDateRange(context, formatter, startMillis, endMillis, DateUtils.FORMAT_ABBREV_ALL, timeZone); // OK
        DateUtils.formatDateRange(context, formatter, startMillis, endMillis, 0); // @violation
        DateUtils.formatDateRange(context, startMillis, endMillis, 5); // @violation
        DateUtils.formatDateRange(context, startMillis, endMillis, DateUtils.FORMAT_NUMERIC_DATE); // OK
        DateUtils.formatDateRange(context, startMillis, endMillis, DateUtils.FORMAT_NO_MIDNIGHT); // OK
        DateUtils.formatDateRange(context, formatter, startMillis, endMillis, -1, timeZone); // @violation
    }
}
