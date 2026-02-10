package ti;

import java.io.File;

import dalvik.system.DexClassLoader;

import android.app.Activity;
import android.content.Context;
import android.os.Environment;

/* OPT : -taint_rule_propagate_all */
public class ANDROID_CLASS_LOADING_HIJACKING_Testcase {
    private Activity mActivity;

    private String test1() {
        String efi = null;

        String defaultLibPath = "/Plugins/effectjava.jar";
        File dexOutputDir = mActivity.getDir("dex", Context.MODE_PRIVATE);
        File externalDir = Environment.getExternalStorageDirectory();
        DexClassLoader dcl = new DexClassLoader(defaultLibPath, /* BUG */
                externalDir.getAbsolutePath(),
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

    private String test2() {
        String efi = null;

        String defaultLibPath = "/Plugins/effectjava.jar";
        File tmpDir = new File("data/local/tmp/optdexjars/");
        File externalDir = Environment.getExternalStorageDirectory();
        DexClassLoader dcl = new DexClassLoader(defaultLibPath, /* SAFE */
                tmpDir.getAbsolutePath(),
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

    private String test3() {
        String efi = null;

        String defaultLibPath = "/Plugins/effectjava.jar";
        File tmpDir = new File("data/local/tmp/optdexjars/");
        File externalDir = Environment.getExternalStorageDirectory();
        DexClassLoader dcl = new DexClassLoader(defaultLibPath, /* BUG */
                tmpDir.getPath(),
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