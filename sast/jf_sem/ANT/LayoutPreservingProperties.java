package ant;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;

/**
 * User: starblood
 * Date: 5/3/13
 * Time: 1:18 PM
 */
public class LayoutPreservingProperties {
    public void saveAs(File dest) throws IOException {
        FileOutputStream fos = new FileOutputStream(dest);
        store(fos, null); /* BUG */ // Resource Leak
        fos.close();
    }

    public void store(FileOutputStream fos, byte [] buffer) throws IOException {
        fos.write(buffer); // IOException thrown
    }
}
