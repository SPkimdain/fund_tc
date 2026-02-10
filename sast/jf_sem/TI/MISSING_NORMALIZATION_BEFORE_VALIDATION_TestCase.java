package ti;

import java.io.*;

class MISSING_NORMALIZATION_BEFORE_VALIDATION_TestCase {

    private boolean isInSecureDir(File file) {
        return file.isDirectory() && file.getAbsolutePath().contains("secure");
    }

    public void violation1(String[] args) throws IOException {
        File file = new File("/img/" + args[0]);
        if (!isInSecureDir(file)) {
            throw new IllegalArgumentException();
        }
        FileOutputStream fis = new FileOutputStream(file);              /* BUG */
        // ...
    }

    public void violation2(String[] args) throws IOException {
        File file = new File("/img/" + args[0]);
        if (!isInSecureDir(file)) {
            throw new IllegalArgumentException();
        }
        String canonicalPath = file.getCanonicalPath();
        FileOutputStream fis = new FileOutputStream(canonicalPath);     /* BUG */
        // ...
    }

    public void good(String[] args) throws IOException {
        File file = new File("/img/" + args[0]);
        if (!isInSecureDir(file)) {
            throw new IllegalArgumentException();
        }
        String canonicalPath = file.getCanonicalPath();
        if (!canonicalPath.equals("/img/java/file1.txt") &&
                !canonicalPath.equals("/img/java/file2.txt")) {
            // Invalid file; handle error
        }
        FileInputStream fis = new FileInputStream(canonicalPath);       /* SAFE */
    }
}