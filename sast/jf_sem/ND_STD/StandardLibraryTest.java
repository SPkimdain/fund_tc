package nd_std;

import java.io.File;

/**
 * Created with IntelliJ IDEA.
 * User: starblood
 * Date: 12. 11. 14.
 * Time: 오전 11:14
 * To change this template use File | Settings | File Templates.
 */
public class StandardLibraryTest {
    public void test() {
        File file = new File("abc.txt");

        File pFile = file.getParentFile();

        pFile.toString(); /* BUG */
    }
    public void test2() {
        File file = new File("abc.txt");

        String str = file.getParent();
        str.toUpperCase(); /* BUG */
    }
}
