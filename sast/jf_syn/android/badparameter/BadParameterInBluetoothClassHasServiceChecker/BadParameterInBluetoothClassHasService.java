package com.fasoo.javafinch.syn.checker.android.badparameter;

import android.bluetooth.BluetoothClass;

/**
 * KEPCO_RULE_130
 */

public class BadParameterInBluetoothClassHasService {
    public void tester(BluetoothClass bluetoothClass) {
        bluetoothClass.hasService(1); // @violation
        bluetoothClass.hasService(BluetoothClass.Service.OBJECT_TRANSFER); // OK
        bluetoothClass.hasService(20); // @violation
        bluetoothClass.hasService(BluetoothClass.Service.LIMITED_DISCOVERABILITY); // OK
        bluetoothClass.hasService(BluetoothClass.Service.TELEPHONY); // OK
        bluetoothClass.hasService(-100); // @violation
    }
}
