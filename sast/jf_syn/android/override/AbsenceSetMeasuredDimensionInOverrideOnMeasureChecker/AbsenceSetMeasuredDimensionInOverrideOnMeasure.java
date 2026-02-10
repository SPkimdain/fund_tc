package com.fasoo.javafinch.syn.checker.android.override;

import android.content.Context;
import android.view.View;
import android.view.ViewGroup;

/**
 * KEPCO_RULE_202
 */

public class AbsenceSetMeasuredDimensionInOverrideOnMeasure {
    public void foo() {

    }

    private class Tester1 extends View {
        public Tester1(Context context) {
            super(context);
        }

        @Override
        public void onMeasure(int widthMeasureSpec, int heightMeasureSpec) { // OK
            foo();
            setMeasuredDimension(getSuggestedMinimumWidth(), getSuggestedMinimumHeight());
        }
    }

    private abstract class Tester2 extends ViewGroup {
        public Tester2(Context context) {
            super(context);
        }

        public void onMeasure(int widthMeasureSpec, int heightMeasureSpec) { // @violation, overriding without setMeasuredDimension
            foo();
            foo();
            foo();
        }
    }
}
