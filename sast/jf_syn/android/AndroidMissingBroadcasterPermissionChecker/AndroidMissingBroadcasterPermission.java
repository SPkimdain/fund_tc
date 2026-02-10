package com.example.android;

import android.annotation.TargetApi;
import android.app.Activity;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.BatteryManager;
import android.os.PowerManager;
import android.widget.Toast;

public class MainActivity extends Activity {

    BroadcastReceiver br = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            if (intent.getAction().equals(Intent.ACTION_BATTERY_CHANGED)) {
                Toast toast = Toast.makeText(context, "Battery status is changed.", Toast.LENGTH_LONG);
                toast.show();
            } else if (intent.getAction().equals(Intent.ACTION_SCREEN_ON)) {
                Toast toast = Toast.makeText(context, "Screen on.", Toast.LENGTH_LONG);
                toast.show();
            }
        }
    };

    public static boolean isConnected(Context context) {
        Intent intent = context.registerReceiver(null, new IntentFilter(Intent.ACTION_BATTERY_CHANGED)); // @violation
        int plugged = intent.getIntExtra(BatteryManager.EXTRA_PLUGGED, -1);
        return plugged == BatteryManager.BATTERY_PLUGGED_AC || plugged == BatteryManager.BATTERY_PLUGGED_USB;
    }

    public void registerNetworkStateReceiver(Context mContext) {
        IntentFilter filter = new IntentFilter();
        filter.addAction(Intent.ACTION_BATTERY_CHANGED);
        filter.addAction(Intent.ACTION_SCREEN_ON);
        mContext.getApplicationContext().registerReceiver(br, filter); // @violation
        
        Context c = mContext.getApplicationContext();
        c.registerReceiver(br, filter); // @violation
    }

    @TargetApi(23)
    private void listenForIdle(Context context) {
        context.registerReceiver(new BroadcastReceiver() { // @violation
            @Override
            public void onReceive(Context context, Intent intent) {
                // TODO
            }
        }, new IntentFilter(PowerManager.ACTION_DEVICE_IDLE_MODE_CHANGED));
    }

    @Override
    protected void onResume() {
        super.onResume();
        IntentFilter filter = new IntentFilter();
        filter.addAction(Intent.ACTION_BATTERY_CHANGED);
        filter.addAction(Intent.ACTION_SCREEN_ON);
        registerReceiver(br, filter); // @violation
        getApplicationContext().registerReceiver(br, filter); // @violation
    }

    @Override
    protected void onPause() {
        super.onPause();
        unregisterReceiver(br);
    }

}