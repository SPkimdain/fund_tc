package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;

/**
 * KEPCO_RULE_124
 */

public class BadParameterInContextBindService {
    public void tester(Context context, Intent service, ServiceConnection conn) {
        context.bindService(service, conn, 0); // OK
        context.bindService(service, conn, Context.BIND_AUTO_CREATE); // OK
        context.bindService(service, conn, Context.BIND_ALLOW_OOM_MANAGEMENT); // OK
        context.bindService(service, conn, 2); // @violation
        context.bindService(service, conn, -5); // @violation
        context.bindService(service, conn, Context.CONTEXT_INCLUDE_CODE); // @violation
    }
}
