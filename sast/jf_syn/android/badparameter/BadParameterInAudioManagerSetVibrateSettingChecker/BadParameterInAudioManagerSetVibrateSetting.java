package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.media.AudioManager;

/**
 * KEPCO_RULE_182
 */

public class BadParameterInAudioManagerSetVibrateSetting {
    public void tester(AudioManager manager) {
        manager.setVibrateSetting(AudioManager.VIBRATE_TYPE_NOTIFICATION, AudioManager.VIBRATE_SETTING_ON); // OK
        manager.setVibrateSetting(AudioManager.VIBRATE_TYPE_RINGER, AudioManager.VIBRATE_SETTING_ONLY_SILENT); // OK
        manager.setVibrateSetting(0, AudioManager.VIBRATE_SETTING_OFF); // @violation
        manager.setVibrateSetting(AudioManager.VIBRATE_TYPE_RINGER, 1); // @violation
        manager.setVibrateSetting(AudioManager.VIBRATE_SETTING_ONLY_SILENT, AudioManager.VIBRATE_TYPE_NOTIFICATION); // @violation 2
    }
}
