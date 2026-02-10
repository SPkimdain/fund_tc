package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.content.pm.PackageManager;

/**
 * KEPCO_RULE_128
 */

public class BadParameterInPackageManagerSetApplicationEnabledSetting {
    public void tester(PackageManager manager, String packageName) {
        manager.setApplicationEnabledSetting(packageName, 0, 1); // @violation 2
        manager.setApplicationEnabledSetting(packageName, PackageManager.COMPONENT_ENABLED_STATE_DEFAULT, 0); // OK
        manager.setApplicationEnabledSetting(packageName, PackageManager.COMPONENT_ENABLED_STATE_DISABLED, PackageManager.DONT_KILL_APP); // OK
        manager.setApplicationEnabledSetting(packageName, PackageManager.COMPONENT_ENABLED_STATE_ENABLED, 0); // OK
        manager.setApplicationEnabledSetting(packageName, 2, 0); // @violation
    }
}
