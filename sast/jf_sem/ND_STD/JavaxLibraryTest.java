package nd_std;

import javax.management.Descriptor;

/**
 * Created with IntelliJ IDEA.
 * User: starblood
 * Date: 12. 11. 14.
 * Time: 오전 11:19
 * To change this template use File | Settings | File Templates.
 */
public class JavaxLibraryTest {
    public void test(Descriptor desc) {
        String [] list = desc.getFields();

        list.toString(); /* SAFE */
    }
}
