package ti;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Path;
import java.nio.file.Files;
import java.nio.file.LinkOption;
import java.nio.file.attribute.BasicFileAttributes;

class DO_NOT_OPERATE_ON_UNTRUSTED_FILE_LINKS_TestCase {
    void test() {
        String filename = "";
        Path path = new File(filename).toPath();
        try {
            BasicFileAttributes attr =
                    Files.readAttributes(path, BasicFileAttributes.class);

            // Check
            if (!attr.isRegularFile()) {
                System.out.println("Not a regular file");
                return;
            }
            // other necessary checks

            // Use
            InputStream in = null;
            try {
                in = Files.newInputStream(path); /* BUG */
                // read file
            } finally {
                if(in != null) in.close();
            }
        } catch (IOException x) {
            // handle error
        }
    }
    void testSafe() {
        String filename = "";
        Path path = new File(filename).toPath();
        try {
            BasicFileAttributes attr = Files.readAttributes(
                    path, BasicFileAttributes.class, LinkOption.NOFOLLOW_LINKS);

            // Check
            if (!attr.isRegularFile()) {
                System.out.println("Not a regular file");
                return;
            }
            // other necessary checks

            // Use
            InputStream in = null;
            try {
                in = Files.newInputStream(path);
                // read file
            } finally {
                if(in != null) in.close();
            }
        } catch (IOException x) {
            // handle error
        }
    }
}