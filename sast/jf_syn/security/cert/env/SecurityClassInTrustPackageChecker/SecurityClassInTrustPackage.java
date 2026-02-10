package security;

import untrusted.RetValue; // @violation
import java.io.*;
import trusted.*;

public class SecurityClassInTrustPackage {
    private void privilegedMethod() throws IOException {
        try {
            AccessController.doPrivileged(
                    new PrivilegedExceptionAction < Void > () {
                        public Void run() throws IOException, FileNotFoundException {
                            final FileInputStream fis = new FileInputStream("file.txt");
                            try {
                                RetValue rt = new RetValue();
                                if (rt.getValue() == 1) {
                                    // Do something with sensitive file
                                }
                            } finally {
                                fis.close();
                            }
                            return null; // Nothing to return
                        }
                    }
            );
        } catch (PrivilegedActionException e) {
            // Forward to handler and log
        }
    }

    public static void main(String[] args) throws IOException {
        MixMatch mm = new MixMatch();
        mm.privilegedMethod();
    }
}