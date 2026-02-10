package security;

import android.webkit.GeolocationPermissions.Callback;
import android.webkit.WebChromeClient;
import java.util.*;
import java.io.*;

public class PrivacyConcernsUsingGeolocationAPI extends WebChromeClient {

    @Override
    public void onGeolocationPermissionsShowPrompt(String origin, Callback callback) {
        super.onGeolocationPermissionsShowPrompt(origin, callback);
        callback.invoke(origin, true, false); // @violation
    }

}