package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.media.AudioManager;

/**
 * KEPCO_RULE_181
 */

public class BadParameterInAudioManagerSetRingerMode {
    public void tester(AudioManager manager) {
        manager.setRingerMode(10); // @violation
        manager.setRingerMode(AudioManager.RINGER_MODE_NORMAL); // OK
        manager.setRingerMode(AudioManager.RINGER_MODE_VIBRATE); // OK
        manager.setRingerMode(20); // @violation
        manager.setRingerMode(AudioManager.RINGER_MODE_SILENT); // OK
        manager.setRingerMode(0); // @violation
    }
}
