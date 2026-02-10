package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.os.Binder;
import android.os.IBinder;
import android.os.Parcel;
import android.os.RemoteException;

/**
 * KEPCO_RULE_201
 */

public class BadParameterInBinderTransact {
    public void tester(Binder binder, Parcel data, Parcel reply, int flags) {
        try {
            binder.transact(IBinder.FIRST_CALL_TRANSACTION, data, reply, flags); // OK
            binder.transact(IBinder.LAST_CALL_TRANSACTION, data, reply, flags); // OK
            binder.transact(0, data, reply, flags); // @violation
            binder.transact(1, data, reply, flags); // OK
            binder.transact(IBinder.FIRST_CALL_TRANSACTION + 10, data, reply, flags); // OK
            binder.transact(16777215, data, reply, flags); // OK
            binder.transact(20000000, data, reply, flags); // @violation
        } catch (RemoteException e) {
        }
    }
}
