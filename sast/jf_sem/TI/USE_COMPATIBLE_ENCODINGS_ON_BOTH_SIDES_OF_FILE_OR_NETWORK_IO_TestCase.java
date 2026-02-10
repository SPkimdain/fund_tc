package ti;

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;

class USE_COMPATIBLE_ENCODINGS_ON_BOTH_SIDES_OF_FILE_OR_NETWORK_IO_TestCase {
    public void test() {
        FileInputStream fis = null;
        try {
            fis = new FileInputStream("SomeFile");
            DataInputStream dis = new DataInputStream(fis);
            byte[] data = new byte[1024];
            dis.readFully(data);
            String result = new String(data); /* BUG */
        } catch (IOException x) {
            // handle error
        } finally {
            if (fis != null) {
                try {
                    fis.close();
                } catch (IOException x) {
                    // Forward to handler
                }
            }
        }
    }
    public void testSafe() {
        FileInputStream fis = null;
        try {
            fis = new FileInputStream("SomeFile");
            DataInputStream dis = new DataInputStream(fis);
            byte[] data = new byte[1024];
            dis.readFully(data);
            String encoding = "SomeEncoding"; // for example, "UTF-16LE"
            String result = new String(data, encoding);
        } catch (IOException x) {
            // handle error
        } finally {
            if (fis != null) {
                try {
                    fis.close();
                } catch (IOException x) {
                    // Forward to handler
                }
            }
        }
    }
}