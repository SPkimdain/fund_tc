package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.RectF;

/**
 * KEPCO_RULE_137
 */

public class BadParameterInCanvasSaveLayer {
    public void tester(Canvas canvas, RectF bounds, Paint paint, float left, float top, float right, float bottom, int alpha) {
        int clip_has_alpha = Canvas.CLIP_SAVE_FLAG | Canvas.HAS_ALPHA_LAYER_SAVE_FLAG;

        canvas.saveLayer(bounds, paint, Canvas.CLIP_SAVE_FLAG); // OK
        canvas.saveLayer(left, top, right, bottom, paint, Canvas.FULL_COLOR_LAYER_SAVE_FLAG | Canvas.HAS_ALPHA_LAYER_SAVE_FLAG); // OK
        canvas.saveLayer(bounds, paint, Canvas.MATRIX_SAVE_FLAG & Canvas.HAS_ALPHA_LAYER_SAVE_FLAG); // @violation
        canvas.saveLayer(left, top, right, bottom, paint, 0); // @violation
        canvas.saveLayer(bounds, paint, clip_has_alpha | Canvas.MATRIX_SAVE_FLAG); // OK
        canvas.saveLayerAlpha(bounds, alpha, Canvas.ALL_SAVE_FLAG); // OK
        canvas.saveLayerAlpha(bounds, alpha, Canvas.MATRIX_SAVE_FLAG | Canvas.FULL_COLOR_LAYER_SAVE_FLAG | Canvas.HAS_ALPHA_LAYER_SAVE_FLAG); // OK
        canvas.saveLayerAlpha(left, top, right, bottom, alpha, 31); // @violation
    }
}
