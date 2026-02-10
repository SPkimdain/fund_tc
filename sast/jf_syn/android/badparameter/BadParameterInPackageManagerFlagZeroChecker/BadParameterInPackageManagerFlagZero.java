package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.content.ComponentName;
import android.content.pm.PackageManager;

/**
 * KEPCO_RULE_204
 */

public class BadParameterInPackageManagerFlagZero {
    public void tester(PackageManager manager, ComponentName className, String targetPackage, String name) {
        try {
            manager.getInstrumentationInfo(className, 0); // OK
            manager.getInstrumentationInfo(className, 1); // @violation
            manager.queryInstrumentation(targetPackage, 0); // OK
            manager.queryInstrumentation(targetPackage, -1); // @violation
            manager.resolveContentProvider(name, 0); // OK
            manager.resolveContentProvider(name, 5); // @violation
        } catch(PackageManager.NameNotFoundException e) {
        }
    }
}
