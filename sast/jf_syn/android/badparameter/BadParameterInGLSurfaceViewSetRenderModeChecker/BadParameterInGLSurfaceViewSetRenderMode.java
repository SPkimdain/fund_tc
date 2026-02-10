package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.opengl.GLSurfaceView;

/**
 * KEPCO_RULE_165
 */

public class BadParameterInGLSurfaceViewSetRenderMode {
    public void tester(GLSurfaceView view) {
        view.setRenderMode(GLSurfaceView.RENDERMODE_CONTINUOUSLY); // OK
        view.setRenderMode(GLSurfaceView.RENDERMODE_WHEN_DIRTY); // OK
        view.setRenderMode(0); // @violation
        view.setRenderMode(-1); // @violation
        view.setRenderMode(7); // @violation
    }
}
