// WHITESPACE.WHILE_KEYWORD
package cc;

import org.apache.jasper.tagplugins.jstl.core.Catch;

import java.lang.Exception;

public class BadWhitespaceWhileKeyword {
    public void goodTest() {
        while
        (cnt < 10) {
            // Do something ...
        }
    }

    public void badTest () {
        while(cnt < 10) { // @violation
            // Do something ...
        }
    }

    public void goodTest2() {
        while (cnt < 10) {
            // Do something ...
        }
    }
}