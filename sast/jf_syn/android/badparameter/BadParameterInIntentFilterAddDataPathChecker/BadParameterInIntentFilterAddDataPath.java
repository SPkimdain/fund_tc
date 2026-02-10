package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.content.IntentFilter;
import android.os.PatternMatcher;

/**
 * KEPCO_RULE_136
 */

public class BadParameterInIntentFilterAddDataPath {
    public void tester(IntentFilter filter, String path) {
        filter.addDataPath(path, PatternMatcher.PATTERN_LITERAL); // OK
        filter.addDataPath(path, PatternMatcher.PATTERN_PREFIX); // OK
        filter.addDataPath(path, 0); // @violation
        filter.addDataPath(path, 1); // @violation
        filter.addDataPath(path, PatternMatcher.PATTERN_SIMPLE_GLOB); // OK
    }
}
