package security;

import java.io.FileInputStream;
import java.security.AccessController;
import java.security.PrivilegedAction;

public class LeakInformationPrivilegedBlock {

    public class GrandTest extends Test {
        // More implementation here ...
    }

    public class Test implements PrivilegedAction<Void> {
        public Void run() {
            return null;  //To change body of implemented methods use File | Settings | File Templates.
        }
    }

    public static PrivilegedAction<Void> getPrivilegedAction() {
        // Do something ...
    }

    public static PrivilegedExceptionAction<FileInputStream> getPrivilegedExceptionAction() {
        // Do something ...
    }

    public static Test getTest() {
        // Do something ...
    }

    public static GrandTest getGrandTest() {
        // Do something ...
    }

    public static void changePassword() {
        FileInputStream fin = openPasswordFile();
        if (fin == null) {
            // no password file; handle error
        }

        // test old password with password in file contents; change password
    }

    public static FileInputStream publicPasswordFile() {
        AccessController.doPrivileged(new PrivilegedAction<Void>() { // @violation
            public Void run() {
                try {
                    // Sensitive action; can't be done outside
                    // doPrivileged() block
                    fin[0] = new FileInputStream(password_file);
                } catch (FileNotFoundException x) {
                    // report to handler
                }
                return null;
            }
        });
    }

    private static FileInputStream openPasswordFile() {

        PrivilegedAction<Void> action;
        PrivilegedExceptionAction<FileInputStream> exceptionAction;
        PrivilegedAction<FileInputStream> fileAction;
        Test testAction;

        final String password_file = "password";
        final FileInputStream fin[] = { null };

        try {
            fin = AccessController.doPrivileged( // @violation
                    new PrivilegedExceptionAction<FileInputStream>() {
                        public FileInputStream run() throws FileNotFoundException {
                            // Sensitive action; can't be done outside privileged block
                            FileInputStream in = new FileInputStream(password_file);
                            return in;
                        }
                    });
        } catch (PrivilegedActionException x) {
            Exception cause = x.getException();
            if (cause instanceof FileNotFoundException) {
                throw (FileNotFoundException) cause;
            } else {
                throw new Error("Unexpected exception type", cause);
            }
        }

        AccessController.doPrivileged(new PrivilegedAction<Void>() {
            public Void run() {
                try {
                    // Sensitive action; can't be done outside
                    // doPrivileged() block
                    fin[0] = new FileInputStream(password_file);
                } catch (FileNotFoundException x) {
                    // report to handler
                }
                return null;
            }
        });

        AccessController.doPrivileged(getPrivilegedAction());
        AccessController.doPrivileged(getPrivilegedExceptionAction()); // @violation
        AccessController.doPrivileged(getTest());
        AccessController.doPrivileged(getGrandTest());
        AccessController.doPrivileged(action);
        AccessController.doPrivileged(exceptionAction); // @violation
        AccessController.doPrivileged(fileAction); // @violation
        AccessController.doPrivileged(testAction);

        return fin[0];
    }
}
