package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.widget.AbsListView;
import android.widget.GridView;
import android.widget.ListView;

/**
 * KEPCO_RULE_177
 */

public class BadParameterInAbsListViewSetChoiceMode {
    public void tester(AbsListView v1, GridView v2, ListView v3) {
        v1.setChoiceMode(0); // @violation
        v1.setChoiceMode(AbsListView.CHOICE_MODE_NONE); // OK
        v2.setChoiceMode(AbsListView.CHOICE_MODE_SINGLE); // OK
        v2.setChoiceMode(3); // @violation
        v3.setChoiceMode(AbsListView.CHOICE_MODE_MULTIPLE); // OK
        v3.setChoiceMode(-100); // @violation
    }
}
