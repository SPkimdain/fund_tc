package null_return;

/**
 * Created with IntelliJ IDEA.
 * User: starblood
 * Date: 4/2/13
 * Time: 4:58 PM
 * To change this template use File | Settings | File Templates.
 */
public class ResourceUtil {
    public static FileResource asFileResource(FileProvider provider) {
        if (provider instanceof FileResource || provider == null) {
            return (FileResource)provider;
        }
        return new FileResource();
    }
}
