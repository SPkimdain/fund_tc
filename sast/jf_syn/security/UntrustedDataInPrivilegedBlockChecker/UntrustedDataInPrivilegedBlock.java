package security;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.lang.Exception;
import java.lang.String;
import java.security.AccessController;
import java.security.PrivilegedActionException;
import java.security.PrivilegedExceptionAction;

public class UntrustedDataInPrivilegedBlock {
    private void privilegedMethod(final String filename)
            throws FileNotFoundException {
        try {
            FileInputStream fis =
                    (FileInputStream) AccessController.doPrivileged(
                            new PrivilegedExceptionAction() {
                                public FileInputStream run() throws FileNotFoundException {
                                    return new FileInputStream(filename); // @violation
                                }
                            }
                    );
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
                                    return new FileInputStream(cleanFilename);
                                }
                            }
                    );
            // do something with the file and then close it
        } catch (PrivilegedActionException e) {
            // forward to handler
        }
    }

    static final String FILEPATH = "/path/to/protected/file/fn.ext";

    private void privilegedMethod3() throws FileNotFoundException {
        try {
            FileInputStream fis =
                    (FileInputStream) AccessController.doPrivileged(
                            new PrivilegedExceptionAction() {
                                public FileInputStream run() throws FileNotFoundException {
                                    return new FileInputStream(FILEPATH);
                                }
                            }
                    );
            // do something with the file and then close it
        } catch (PrivilegedActionException e) {
            // forward to handler and log
        }
    }

    private void privilegedMethod(final String filename)
            throws FileNotFoundException {
        try {
            String dangerous = filename;
            FileInputStream fis =
                    (FileInputStream) AccessController.doPrivileged(
                            new PrivilegedExceptionAction() {
                                public FileInputStream run() throws FileNotFoundException {
                                    return new FileInputStream(dangerous); // @violation
                                }
                            }
                    );
            // do something with the file and then close it
        } catch (PrivilegedActionException e) {
            // forward to handler
        }
    }

    private void privilegedMethod(final String filename)
            throws FileNotFoundException {
        try {
            String dangerous = filename;
            FileInputStream fis =
                    (FileInputStream) AccessController.doPrivileged(
                            new PrivilegedExceptionAction() {
                                String stillDangerous = dangerous; // @violation
                                public FileInputStream run() throws FileNotFoundException {
                                    return new FileInputStream(stillDangerous);
                                }
                            }
                    );
            // do something with the file and then close it
        } catch (PrivilegedActionException e) {
            // forward to handler
        }
    }
}
