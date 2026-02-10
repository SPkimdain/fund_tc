package ant;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Properties;

/**
 * Created with IntelliJ IDEA.
 * User: starblood
 * Date: 5/2/13
 * Time: 5:53 PM
 * To change this template use File | Settings | File Templates.
 */
public class JUnitTask {
    public void executeAsForked() {
        Properties props = new Properties();
        File propsFile = new File("abc");
        FileOutputStream outstream = null;
        try {
            outstream = new FileOutputStream(propsFile);
            props.store(outstream, "Ant JUnitTask generated properties file"); // 여기서 IOException 이 throw 될 수 있다.
            outstream.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    } /* BUG */ // Resource Leak

    public void executeAsForked2() {
        Properties props = new Properties();
        File propsFile = new File("abc");
        FileOutputStream outstream = null;
        try {
            outstream = new FileOutputStream(propsFile);
            outstream.close(); // finally 구문에서 close 를 안해도 resource 가 해제 되었다고 간주한다.
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
