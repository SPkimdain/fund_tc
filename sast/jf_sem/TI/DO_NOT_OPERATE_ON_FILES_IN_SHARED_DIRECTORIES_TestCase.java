package ti;

import java.io.FileInputStream;
import java.io.InputStream;
import java.io.IOException;
import java.io.File;
import java.util.Random;

class DO_NOT_OPERATE_ON_FILES_IN_SHARED_DIRECTORIES_TestCase {
    void test(String file) throws Exception {
        InputStream in = null;
        try {
            in = new FileInputStream(file); /* BUG */
            // ...
        } finally {
            try {
                if (in !=null) { in.close();}
            } catch (IOException x) {
                // handle error
            }
        }
    }
    boolean isSafeDirectory(File path) {
        // dummy
        int x = new Random().nextInt(); /* BUG */
        return x > 100;
    }
    void testSafe(String file) throws Exception {
        File path = new File(file);

        if(isSafeDirectory(path)) {

            InputStream in = null;

            try {
                in = new FileInputStream(path);
                // ...
            } finally {
                try {
                    if (in != null) {
                        in.close();
                    }
                } catch (IOException x) {
                    // handle error
                }
            }

        }
    }
}