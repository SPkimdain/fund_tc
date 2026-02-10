// WHITESPACE.FOR_KEYWORD
package cc;

import org.apache.jasper.tagplugins.jstl.core.Catch;

import java.lang.Exception;

public class BadWhitespaceForKeyword {
    public void goodTest() {
        for /* Comment whitespace */(int i=0; i<10; i++) {
            // Do something ...
        }
        for (int i=0; i<10; i++) {
            // Do something ...
        }
    }

    public void badTest () {
        for/* Comment whitespace */(int i=0; i<10; i++) { // @violation
            // Do something ...
        }
        for(int i=0; i<10; i++) { // @violation
            // Do something ...
        }
    }
}