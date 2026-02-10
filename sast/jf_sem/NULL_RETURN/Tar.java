package null_return;

import java.io.File;
import java.util.Iterator;

/**
 * Created with IntelliJ IDEA.
 * User: starblood
 * Date: 4/2/13
 * Time: 4:54 PM
 * To change this template use File | Settings | File Templates.
 */
public class Tar {
    public void test(ResourceCollection collection) {
        Iterator iter = collection.iterator();
        Resource res = (Resource)iter.next();
        FileResource resource = ResourceUtil.asFileResource((FileProvider)res.as(FileProvider.class));

        File base = resource.getBaseDir(); // Klocwork NPE.RET
    }
}
