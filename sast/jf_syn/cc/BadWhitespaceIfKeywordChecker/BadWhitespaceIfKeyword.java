// WHITESPACE.IF_KEYWORD
package cc;

import org.apache.jasper.tagplugins.jstl.core.Catch;

import java.lang.Exception;

public class BadWhitespaceIfKeyword {

    public BadWhitespaceKeyword(double d) {

    }

    public BadWhitespaceKeyword (int a) {

    }

    public void func(int a) {
        // Do something ...
    }

    public void goodTest() {
        if (cnt < 10) {
            // Do something ...
        } else if (cnt < 20) {
            // Do something ...
        } else {
            // Do something ...
        }
    }

    public void badTest () {
        if(cnt < 10) { // @violation
            // Do something ...
        } else if(cnt < 20) { // @violation
            // Do something ...
        } else {
            // Do something ...
        }
    }
}