package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.os.Message;

/**
 * KEPCO_RULE_164
 */

public class BadParameterInAlertDialogSetButton {
    public void tester(AlertDialog dialog, CharSequence text, Message msg, DialogInterface.OnClickListener listener) {
        dialog.setButton(DialogInterface.BUTTON_NEUTRAL, text, msg); // OK
        dialog.setButton(DialogInterface.BUTTON_POSITIVE, text, listener); // OK
        dialog.setButton(0, text, msg); // @violation
        dialog.setButton(-10, text, listener); // @violation
    }
}
