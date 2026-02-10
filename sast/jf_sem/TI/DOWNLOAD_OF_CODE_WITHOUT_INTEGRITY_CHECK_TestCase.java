package ti;

import java.net.URL;
import java.net.URLClassLoader;

/**
 * Writer: Gyuhang Shim
 * Date: 9/14/12
 */
public class DOWNLOAD_OF_CODE_WITHOUT_INTEGRITY_CHECK_TestCase {
    void test() throws Exception {
        URL[] classURLs = new URL[]{
                new URL("")
        };
        URLClassLoader loader = new URLClassLoader(classURLs);
        Class loadedClass = Class.forName("LoadMe", true, loader);
        String str = (String)loadedClass.newInstance(); /* */
    }
    void safeTest() throws Exception {
        URL[] classURLs = new URL[]{
                new URL("")
        };
        URLClassLoader loader = new URLClassLoader(classURLs);
        Class loadedClass = Class.forName("LoadMe", true, loader);
        if(loadedClass.getName() != loadedClass.getSimpleName()) return;
        String str = (String)loadedClass.newInstance(); /* SAFE */
    }

    int getSomeInt() { return -1; }
    void testComplicated() throws Exception {
        URL[] classURLs = new URL[]{
                new URL("")
        };
        URLClassLoader loader = new URLClassLoader(classURLs);
        Class loadedClass = null;
        if (getSomeInt() > 0) { // getSomeInt returns -1, so go to false branch
            loadedClass = this.getClass();
        } else {
            loadedClass = Class.forName("LoadMe", true, loader); // tainted
        }

        String str = (String)loadedClass.newInstance(); /* */
    }
}
