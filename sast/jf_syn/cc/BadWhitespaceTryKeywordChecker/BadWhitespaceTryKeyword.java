// WHITESPACE.TRY_KEYWORD
package cc;

import org.apache.jasper.tagplugins.jstl.core.Catch;

import java.lang.Exception;

public class BadWhitespaceTryKeyword {
    public void goodTest() {
        try {
            // Do something ...
        } catch (Exception e) {
            // Do something ...
        }
    }

    public void badTest () {
        try {
            // Do something ...
        } catch(Exception e) { // @violation
            // Do something ...
        }
    }
}