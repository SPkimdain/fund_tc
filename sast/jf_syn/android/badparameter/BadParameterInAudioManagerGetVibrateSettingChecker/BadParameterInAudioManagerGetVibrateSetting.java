package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.media.AudioManager;

/**
 * KEPCO_RULE_180
 */

public class BadParameterInAudioManagerGetVibrateSetting {
    public void tester(AudioManager manager) {
        manager.getVibrateSetting(AudioManager.VIBRATE_TYPE_NOTIFICATION); // OK
        manager.getVibrateSetting(AudioManager.VIBRATE_TYPE_RINGER); // OK
        manager.getVibrateSetting(10); // @violation
        manager.getVibrateSetting(-3); // @violation
    }
}
