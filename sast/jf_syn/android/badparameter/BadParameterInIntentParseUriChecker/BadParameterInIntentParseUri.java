package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.content.Intent;

import java.net.URISyntaxException;

/**
 * KEPCO_RULE_125
 */

public class BadParameterInIntentParseUri {
    public void tester(String uri) {
        try {
            Intent.parseUri(uri, Intent.URI_INTENT_SCHEME); // OK
            Intent.parseUri(uri, -2); // @violation
            Intent.parseUri(uri, 0); // OK
            Intent.parseUri(uri, Intent.URI_ANDROID_APP_SCHEME); // OK
            Intent.parseUri(uri, 10); // @violation
        } catch (URISyntaxException e) {
        }
    }
}
