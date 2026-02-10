package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.content.Context;
import android.net.Uri;

/**
 * KEPCO_RULE_187
 */

public class BadParameterInContextPermissionPid {
    public void tester(Context context, String permission, Uri uri, String readPermission, String writePermission, int uid, int modeFlags, String message) {
        int r;

        r = context.checkPermission(permission, 0, uid); // @violation
        r = context.checkPermission(permission, 1 , uid); // OK
        r = context.checkUriPermission(uri, 3, uid, modeFlags); // OK
        r = context.checkUriPermission(uri, readPermission, writePermission, -1, uid, modeFlags); // @violation
        context.enforcePermission(permission, 10, uid, message); // OK
        context.enforcePermission(permission, -5, uid, message); // @violation
        context.enforceUriPermission(uri, readPermission, writePermission, 0, uid, modeFlags, message); // @violation
        context.enforceUriPermission(uri, 20, uid, modeFlags, message); // OK
    }
}
