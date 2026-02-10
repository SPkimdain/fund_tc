package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.content.ComponentName;
import android.content.pm.PackageManager;

/**
 * KEPCO_RULE_126
 */

public class BadParameterInPackageManagerSetComponentEnabledSetting {
    public void tester(PackageManager manager, ComponentName componentName) {
        manager.setComponentEnabledSetting(componentName, 0, 1); // @violation 2
        manager.setComponentEnabledSetting(componentName, PackageManager.COMPONENT_ENABLED_STATE_DEFAULT, 0); // OK
        manager.setComponentEnabledSetting(componentName, PackageManager.COMPONENT_ENABLED_STATE_DISABLED, PackageManager.DONT_KILL_APP); // OK
        manager.setComponentEnabledSetting(componentName, PackageManager.COMPONENT_ENABLED_STATE_ENABLED, 0); // OK
        manager.setComponentEnabledSetting(componentName, 2, 0); // @violation
    }
}
