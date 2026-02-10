package com.fasoo.javafinch.syn.checker.android.forbidden;

import android.app.PendingIntent;
import android.telephony.SmsManager;

import java.util.ArrayList;

/**
 * KEPCO_RULE_206
 */

public class DoNotSendSms {
    public void tester(SmsManager manager, String destinationAddress, String scAddress, String text,
                       short destinationPort, byte[] data, PendingIntent sentIntent, PendingIntent deliveryIntent,
                       ArrayList<String> parts, ArrayList<PendingIntent> sentIntents, ArrayList<PendingIntent> deliveryIntents) {
        manager.divideMessage(text); // OK
        manager.sendDataMessage(destinationAddress, scAddress, destinationPort, data, sentIntent, deliveryIntent); // @violation
        manager.sendMultipartTextMessage(destinationAddress, scAddress, parts, sentIntents, deliveryIntents); // @violation
        manager.getCarrierConfigValues(); // OK
        manager.sendTextMessage(destinationAddress, scAddress, text, sentIntent, deliveryIntent); // @violation
    }
}
