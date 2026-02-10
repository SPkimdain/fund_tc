package ti;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.lang.String;

import android.content.Context;
import android.os.Environment;
import android.telephony.CellLocation;
import android.telephony.TelephonyManager;

public class INFORMATION_LEAK_ANDROID_TestCase {

    /**
     * Get the cell location of the device
     * @param context target context
     * @return the cell location
     */
    public CellLocation getCellLocation(Context context) {
        TelephonyManager tm = (TelephonyManager)context.getSystemService(Context.TELEPHONY_SERVICE);
        if(tm != null) {
            return tm.getCellLocation();
        } else {
            return null;
        }
    }

    /**
     * Test function 1
     * @param context target context
     */
    public void function(Context context) {
        File mSdFile = Environment.getExternalStorageDirectory();
        String mSdPath = mSdFile.getAbsolutePath();
        File dir = new File(mSdPath + "/dir");
        dir.mkdir();
        File file = new File(mSdPath + "/dir/file.txt");
        FileOutputStream fos = null;
        try {
            fos = new FileOutputStream(file);
            TelephonyManager tm = (TelephonyManager)context.getSystemService(Context.TELEPHONY_SERVICE);
            if(tm != null) {
                fos.write(tm.getLine1Number().getBytes()); /* BUG */
            }

        } catch (Exception e) {
            // Do something ...
        } finally {
            if (fos != null) {
                try {
                    fos.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    /**
     * Test function 2
     * @param context target context
     */
    public void function2(Context context) {
        File mSdFile = Environment.getExternalStorageDirectory();
        String mSdPath = mSdFile.getAbsolutePath();
        File dir = new File(mSdPath + "/dir");
        dir.mkdir();
        File file = new File(mSdPath + "/dir/file.txt");
        try {
            FileOutputStream fos = new FileOutputStream(file);
            PrintWriter pw = new PrintWriter(fos);
            CellLocation cellLoc = getCellLocation(context);
            pw.write(cellLoc.toString()); /* BUG */
            fos.close();
            pw.close();
        } catch (Exception e) {
            // Do something ...
        }
    }
}
