package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.speech.tts.TextToSpeech;

import java.util.HashMap;

/**
 * KEPCO_RULE_152
 */

public class BadParameterInTextToSpeechQueueMode {
    public void tester(TextToSpeech speech, String earcon, String text, long durationInMs, HashMap<String, String> params) {
        speech.playEarcon(earcon, 0, params); // @violation
        speech.playEarcon(earcon, TextToSpeech.QUEUE_ADD, params); // OK
        speech.playSilence(durationInMs, TextToSpeech.QUEUE_FLUSH, params); // OK
        speech.playSilence(durationInMs, 2, params); // @violation
        speech.speak(text, TextToSpeech.QUEUE_ADD, params); // OK
        speech.speak(text, 1, params); // @violation
    }
}
