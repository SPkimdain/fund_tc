package rl;

import java.io.IOException;
import java.io.InputStream;
import java.util.zip.ZipInputStream;

/**
 * User: starblood
 * Date: 5/22/13
 * Time: 11:22 AM
 */
public class ZipInputStreamTest {
    private ZipInputStream jarStream;

    public ZipInputStreamTest(InputStream stream) throws IOException {
        super();

        jarStream = new ZipInputStream(stream); // klocwork, resource leak
    }

}
