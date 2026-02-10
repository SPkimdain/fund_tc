package ti;

import java.io.File;

import dalvik.system.DexClassLoader;

import android.app.Activity;
import android.content.Context;
import android.os.Environment;

public class ANDROID_CLASS_LOADING_HIJACKING_ABSOLUTE_PATH_Testcase {
    private Activity mActivity;

    private String test1(File myDir) {
        String efi = null;

        String defaultLibPath = "/Plugins/effectjava.jar";
        File dexOutputDir = mActivity.getDir("dex", Context.MODE_PRIVATE);
        File externalDir = Environment.getExternalStorageDirectory();
        DexClassLoader dcl = new DexClassLoader(defaultLibPath, /* BUG */
                myDir.getPath(),
                null,
                ClassLoader.getSystemClassLoader());
        try {
            Class<?> clazz = dcl.loadClass("EffectJavaImpl");
            efi = (String) clazz.newInstance();
        } catch (ClassNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (InstantiationException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

        return efi;

    }


    private String test2(File myDir) {
        String efi = null;

        String defaultLibPath = "/Plugins/effectjava.jar";
        File dexOutputDir = mActivity.getDir("dex", Context.MODE_PRIVATE);
        File externalDir = Environment.getExternalStorageDirectory();
        DexClassLoader dcl = new DexClassLoader(defaultLibPath, /* BUG */
                myDir.toString(),
                null,
                ClassLoader.getSystemClassLoader());
        try {
            Class<?> clazz = dcl.loadClass("EffectJavaImpl");
            efi = (String) clazz.newInstance();
        } catch (ClassNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (InstantiationException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

        return efi;

    }


}