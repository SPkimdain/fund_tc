package knownMethods;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class NullReturnStdTest {
    public void bufferedReaderTest() {
        BufferedReader br = null;
        try {
            br = new BufferedReader(new FileReader(""));
            String str = br.readLine(); // BufferedReader.readLine() may return null

            str.toUpperCase(); /* BUG */
        } catch (IOException e) {}
        finally {
            if (br != null) {
                try {
                    br.close();
                } catch (IOException e) {}
            }
        }
    }
    public void systemPropertyTest() {
        String ret = System.getProperty("user.dir");
        ret.toUpperCase(); /* SAFE */

        String ret2 = System.getProperty("starblood.home");
        ret2.toLowerCase(); /* BUG */
    }
}