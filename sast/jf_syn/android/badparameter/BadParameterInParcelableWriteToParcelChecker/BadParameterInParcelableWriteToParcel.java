package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.os.Parcel;
import android.os.Parcelable;

/**
 * KEPCO_RULE_205
 */

public class BadParameterInParcelableWriteToParcel {
    public void tester(Parcelable parcelable, Parcel dest) {
        parcelable.writeToParcel(dest, 0); // OK
        parcelable.writeToParcel(dest, 1); // @violation
        parcelable.writeToParcel(dest, 5); // @violation
        parcelable.writeToParcel(dest, Parcelable.PARCELABLE_WRITE_RETURN_VALUE); // OK
    }
}
