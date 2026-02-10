package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.location.Criteria;

/**
 * KEPCO_RULE_150
 */

public class BadParameterInCriteriaSetAccuracy {
    public void tester(Criteria criteria) {
        criteria.setAccuracy(0); // @violation
        criteria.setAccuracy(Criteria.ACCURACY_FINE); // OK
        criteria.setAccuracy(Criteria.ACCURACY_COARSE); // OK
        criteria.setAccuracy(2); // @violation
    }
}
