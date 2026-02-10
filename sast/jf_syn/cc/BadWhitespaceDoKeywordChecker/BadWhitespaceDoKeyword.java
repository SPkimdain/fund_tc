// WHITESPACE.DO_KEYWORD
package cc;

import org.apache.jasper.tagplugins.jstl.core.Catch;

import java.lang.Exception;

public class BadWhitespaceDoKeyword {
    public void goodTest() {
        do {
            // Do something ...
        } while
        (cnt < 10);

        do {
            // Do something ...
        } while (cnt < 10);

    }

    public void badTest () {
        do {
            // Do something ...
        } while(cnt < 10); // @violation
    }
}