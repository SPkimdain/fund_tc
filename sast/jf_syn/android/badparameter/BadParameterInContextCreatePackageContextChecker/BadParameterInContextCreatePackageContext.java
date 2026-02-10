package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.content.Context;
import android.content.pm.PackageManager;

/**
 * KEPCO_RULE_131
 */

public class BadParameterInContextCreatePackageContext {
    public void tester(Context context, String packageName) {
        try {
            context.createPackageContext(packageName, 1); // @violation
            context.createPackageContext(packageName, Context.CONTEXT_INCLUDE_CODE); // OK
            context.createPackageContext(packageName, Context.CONTEXT_IGNORE_SECURITY); // OK
            context.createPackageContext(packageName, Context.BIND_AUTO_CREATE); // @violation
        } catch (PackageManager.NameNotFoundException e) {
        }
    }
}
