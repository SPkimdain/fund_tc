package nd;

import java.util.Random;

/**
 * Writer: Gyuhang Shim
 * Date: 7/5/12
 */
public class ExceptionThrowTest {
    public void exceptionThrowTest() {
        String str;
        try {
            str = exceptionThrowTestHelper();
        } catch (CoreException e) {
            return;
        }
        str.toUpperCase(); /* NOT BUG */
    }
    public String exceptionThrowTestHelper() throws CoreException {
        String str = null;

        str = getString();
        if (str == null) {
            throw new CoreException("abc");
        }
        return str;
    }

    public String getString() {
        int rand = new Random().nextInt();
        if (rand > 0) {
            return "abc";
        } else {
            return null;
        }
    }

    // TODO: klocwork 은 검출하나 Sparrow 는 검출못함
    public void exceptionThrowTest2() {
        exceptionThrowTest2Helper().toUpperCase(); /* BUG */
    }
    public String exceptionThrowTest2Helper() {
        try {
            return getString2();
        } catch (CoreException e) {}
        return null;
    }
    public String getString2() throws CoreException {
        int rand = new Random().nextInt();
        if (rand > 0)
            return "abc";
        else
            throw new CoreException("abc");
    }
}

class CoreException extends Exception {
    public CoreException(String msg) {
        super(msg);
    }
}
