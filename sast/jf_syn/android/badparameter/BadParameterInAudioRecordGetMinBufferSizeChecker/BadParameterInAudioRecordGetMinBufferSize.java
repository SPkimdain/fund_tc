package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.media.AudioFormat;
import android.media.AudioRecord;

/**
 * KEPCO_RULE_184
 */

public class BadParameterInAudioRecordGetMinBufferSize {
    public void tester(int sampleRateInHz, int channelConfig) {
        AudioRecord.getMinBufferSize(sampleRateInHz, channelConfig, AudioFormat.ENCODING_DEFAULT); // OK
        AudioRecord.getMinBufferSize(sampleRateInHz, channelConfig, AudioFormat.ENCODING_PCM_16BIT); // OK
        AudioRecord.getMinBufferSize(sampleRateInHz, channelConfig, 10); // @violation
        AudioRecord.getMinBufferSize(sampleRateInHz, channelConfig, 0); // @violation
        AudioRecord.getMinBufferSize(sampleRateInHz, channelConfig, AudioFormat.ENCODING_INVALID); // OK
    }
}
