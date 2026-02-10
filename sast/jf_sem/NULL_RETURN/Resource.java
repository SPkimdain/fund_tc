package null_return;

/**
 * Created with IntelliJ IDEA.
 * User: starblood
 * Date: 4/2/13
 * Time: 4:54 PM
 * To change this template use File | Settings | File Templates.
 */
public class Resource {
    public Object as(Class clazz) {
        return clazz.isAssignableFrom(getClass()) ? this : null;
    }
}
