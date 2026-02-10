package security;

import java.io.File;
import java.security.AccessController;
import java.io.RandomAccessFile;
import java.security.PrivilegedAction;

public class DoNotBaseSecurityChecksOnUntrustedSources {
    public RandomAccessFile openFile(File f, boolean copyTest) {
        if(copyTest) {
            File copyFile = f.clone();
            return (RandomAccessFile) AccessController.doPrivileged(new PrivilegedAction<Object>() {
                public Object run() {
                    return new RandomAccessFile(copyFile, copyFile.getPath()); // @violation
                }
            });
        }

        return (RandomAccessFile) AccessController.doPrivileged(new PrivilegedAction<Object>() {
            public Object run() {
                return new RandomAccessFile(f, f.getPath()); // @violation
            }
        });
    }
}