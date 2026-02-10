import android.app.Service;

public class ServerService extends Service {
    // ...
    private void d() {
        // ...
//        Intent v1 = new Intent();
//        v1.setAction("com.sample.action.server_running");
//        v1.putExtra("local_ip", v0.h);
//        v1.putExtra("port", v0.i);
//        v1.putExtra("code", v0.g);
//        v1.putExtra("connected", v0.s);
//        v1.putExtra("pwd_predefined", v0.r);
//        if (!TextUtils.isEmpty(v0.t)) {
//            v1.putExtra("connected_usr", v0.t);
//        }
        this.sendBroadcast(v1);     // @violation
    }

    private void d_Safe() {
        // ...
        Intent v1 = new Intent();
        v1.setAction("com.sample.action.server_running");
        v1.putExtra("local_ip", v0.h);
        v1.putExtra("port", v0.i);
        v1.putExtra("code", v0.g);
        v1.putExtra("connected", v0.s);
        v1.putExtra("pwd_predefined", v0.r);
        if (!TextUtils.isEmpty(v0.t)) {
            v1.putExtra("connected_usr", v0.t);
        }
        LocalBroadcastManager.getInstance(this).sendBroadcast(v1);
    }
}