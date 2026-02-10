package com.fasoo.javafinch.syn.checker.android.override;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;

public abstract class AndroidPermissionCheckBypass extends Activity {
    @Override
    protected void onCreate(Bundle savedInstanceState) { // OK
        super.onCreate(savedInstanceState);
    }

    @Override
    protected void onStart() { // OK
        super.onStart();
    }

    protected void onRestart() {
        super.onStart(); // onStart -> onRestart
    }

    protected void onResume() {
        foo();
        super.onResume(); // should be at the head
    }

    protected void onPause() { // OK
        super.onPause();
    }

    @Override
    protected void onStop() { // need super.onStop()
        foo();
    }

    @Override
    public void addContentView(View view, ViewGroup.LayoutParams params) { // OK, it's not lifecycle method
        foo();
    }

    private boolean checkPermission() {
        if(getContext().checkCallingOrSelfPermission("com.test.permission") // @violation
                == PackageManager.PERMISSION_GRANTED) {
            return true;
        }
        return false;
    }
}
