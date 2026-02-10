package com.fasoo.javafinch.syn.checker.android.forbidden;

import android.media.MediaRecorder;

/**
 * KEPCO_RULE_209
 */

public class DoNotRecordMedia {
    public void tester(MediaRecorder recorder) {
        recorder.getMaxAmplitude(); // OK
        recorder.start(); // @violation
        recorder.setAudioChannels(2); // OK
    }
}
