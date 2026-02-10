package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.graphics.Bitmap;

/**
 * KEPCO_RULE_186
 */

public class BadParameterInBitmapCreateBitmap {
    public void tester(int[] colors, int offset, int stride, Bitmap.Config config) {
        Bitmap.createBitmap(0, 10, config); // @violation
        Bitmap.createBitmap(10, 10, config); // OK
        Bitmap.createBitmap(colors, 10, 0, config); // @violation
        Bitmap.createBitmap(colors, offset, stride, 20, 30, config); // OK
        Bitmap.createBitmap(colors, offset, stride, -20, -30, config); // @violation 2
    }
}
