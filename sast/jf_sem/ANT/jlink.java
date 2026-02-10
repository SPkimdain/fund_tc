package ant;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.zip.CRC32;

/**
 *
 * User: starblood
 * Date: 5/2/13
 * Time: 5:45 PM
 */
public class jlink {
    public long calcChecksum(File f) throws IOException {
        FileInputStream fis = new FileInputStream(f);
        return calcChecksum(fis); /* BUG */ // Resource Leak
    }

    public long calcChecksum(FileInputStream fis) throws IOException {
        CRC32 crc = new CRC32();
        byte [] buffer = new byte[1024];
        int len = buffer.length;
        int count = -1;
        int haveRead = 0;

        while ((count = fis.read(buffer, 0, len)) > 0) { // IOException throws
            haveRead += count;
            crc.update(buffer, 0, count);
        }
        fis.close(); // should be closed in finally
        return crc.getValue();
    }
}
