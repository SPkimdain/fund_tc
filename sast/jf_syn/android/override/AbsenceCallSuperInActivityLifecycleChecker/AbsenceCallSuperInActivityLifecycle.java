package com.fasoo.javafinch.syn.checker.android.override;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;

/**
 * KEPCO_RULE_114
 */

public abstract class AbsenceCallSuperInActivityLifecycle extends Activity {
    @Override
    protected void onCreate(Bundle savedInstanceState) { // OK
        super.onCreate(savedInstanceState);
    }

    @Override
    protected void onStart() { // OK
        super.onStart();
    }

    protected void onRestart() { // @violation
        super.onStart(); // onStart -> onRestart
    }

    protected void onResume() { // @violation
        foo();
        super.onResume(); // should be at the head
    }

    protected void onPause() { // OK
        super.onPause();
    }

    @Override
    protected void onStop() { // @violation, need super.onStop()
        foo();
    }

    @Override
    public void addContentView(View view, ViewGroup.LayoutParams params) { // OK, it's not lifecycle method
        foo();
    }

    protected abstract void foo();
}
