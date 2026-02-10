import java.lang.Exception;
import java.security.AccessController;
import java.security.PrivilegedAction;

public class SecurityArgumentDoPrivilege {

    private void privilegedMethod(final String filename)
            throws FileNotFoundException {
        try {
            FileInputStream fis =
                    (FileInputStream) AccessController.doPrivileged(
                            new PrivilegedExceptionAction() {
                                public FileInputStream run() throws FileNotFoundException {
                                    return new FileInputStream(filename);                                // @violation
                                }
                            }
                    );

            Test test;
            FileInputStream fis2 =
                    (FileInputStream) test.getController().doPrivileged(new Privilege(filename).run());     // @violation

            // do something with the file and then close it
        } catch (PrivilegedActionException e) {
            // forward to handler
        }
    }

    private void privilegedMethod2(final String filename)
            throws FileNotFoundException {
        final String cleanFilename;
        try {
            cleanFilename = cleanAFilenameAndPath(filename);
        } catch (Exception e) {
            // log or forward to handler as appropriate based on specification
            // of cleanAFilenameAndPath
        }
        try {
            FileInputStream fis =
                    (FileInputStream) AccessController.doPrivileged(
                            new PrivilegedExceptionAction() {
                                public FileInputStream run() throws FileNotFoundException {
                                    return new FileInputStream(cleanFilename);                  /* Safe */
                                }
                            }
                    );
            // do something with the file and then close it
        } catch (PrivilegedActionException e) {
            // forward to handler
        }
    }

    static final String FILEPATH = "/path/to/protected/file/fn.ext";

    private void privilegedMethod3()
            throws FileNotFoundException {
        try {
            FileInputStream fis =
                    (FileInputStream) AccessController.doPrivileged(
                            new PrivilegedExceptionAction() {
                                public FileInputStream run() throws FileNotFoundException {
                                    return new FileInputStream(FILEPATH);                                /* Safe */
                                }
                            }
                    );
            // do something with the file and then close it
        } catch (PrivilegedActionException e) {
            // forward to handler
        }
    }


}

/**
 * For Testing
 */
public class Privilege implements PrivilegedAction {
    private String fileName;

    public Privilege(String fileName) {
        this.fileName = fileName;
    }

    public FileInputStream run() throws FileNotFoundException {
        return new FileInputStream(filename);
    }
}

/**
 * For Testing
 */
public class Test {
    public AccessController getController() {
        AccessController access;
        return access;
    }
}