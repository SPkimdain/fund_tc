package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.app.AlarmManager;
import android.app.PendingIntent;

/**
 * KEPCO_RULE_163
 */

public class BadParameterInAlarmManagerSet {
    public void tester(AlarmManager alarmManager, long triggerAtMillis, PendingIntent operation) {
        alarmManager.set(AlarmManager.ELAPSED_REALTIME, triggerAtMillis, operation); // OK
        alarmManager.set(AlarmManager.RTC_WAKEUP, triggerAtMillis, operation); // OK
        alarmManager.setInexactRepeating(AlarmManager.ELAPSED_REALTIME_WAKEUP, triggerAtMillis, 100, operation); // @violation
        alarmManager.setInexactRepeating(3, triggerAtMillis, AlarmManager.INTERVAL_FIFTEEN_MINUTES, operation); // @violation
        alarmManager.setInexactRepeating(AlarmManager.RTC, triggerAtMillis, AlarmManager.INTERVAL_HALF_DAY, operation); // OK
        alarmManager.setRepeating(0, triggerAtMillis, AlarmManager.INTERVAL_DAY, operation); // @violation
        alarmManager.setRepeating(AlarmManager.ELAPSED_REALTIME_WAKEUP, triggerAtMillis, AlarmManager.INTERVAL_HOUR, operation); // OK
    }
}
