package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.media.AudioManager;

/**
 * KEPCO_RULE_179
 */

public class BadParameterInAudioManagerAdjustStreamVolume {
    public void tester(AudioManager manager, int flags) {
        manager.adjustStreamVolume(AudioManager.STREAM_VOICE_CALL, AudioManager.ADJUST_SAME, flags); // OK
        manager.adjustStreamVolume(AudioManager.STREAM_SYSTEM, AudioManager.ADJUST_RAISE, flags); // OK
        manager.adjustStreamVolume(AudioManager.STREAM_RING, AudioManager.ADJUST_LOWER, flags); // OK
        manager.adjustStreamVolume(0, 1, flags); // @violation 2
        manager.adjustStreamVolume(10, AudioManager.ADJUST_SAME, flags); // @violation
        manager.adjustStreamVolume(AudioManager.STREAM_RING, -2, flags); // @violation
    }
}
