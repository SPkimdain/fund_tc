package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.media.AudioManager;

/**
 * KEPCO_RULE_183
 */

public class BadParameterInAudioManagerShouldVibrate {
    public void tester(AudioManager manager) {
        manager.shouldVibrate(AudioManager.VIBRATE_TYPE_NOTIFICATION); // OK
        manager.shouldVibrate(0); // @violation
        manager.shouldVibrate(AudioManager.VIBRATE_TYPE_RINGER); // OK
        manager.shouldVibrate(-2); // @violation
        manager.shouldVibrate(AudioManager.VIBRATE_SETTING_ON); // @violation
    }
}
