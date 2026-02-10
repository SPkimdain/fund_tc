package null_return;

import java.io.File;

/**
 * Created with IntelliJ IDEA.
 * User: starblood
 * Date: 4/2/13
 * Time: 4:57 PM
 * To change this template use File | Settings | File Templates.
 */
public class FileResource extends Resource {
    public File getBaseDir() {
        return new File("abc");
    }

}
