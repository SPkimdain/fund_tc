package nd_std;

import java.net.URI;

/**
 * Writer: Gyuhang Shim
 * Date: 7/5/12
 */
public class ND_STD_IfTest {
    public void test(URI uri) {
        String schemem = uri.getScheme();
        schemem.toLowerCase(); /* BUG */
        if (schemem != null) {
            schemem.toLowerCase(); /* SAFE */
        }
    }
}
