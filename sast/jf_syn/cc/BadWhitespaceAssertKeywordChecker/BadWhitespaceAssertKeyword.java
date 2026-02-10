// WHITESPACE.ASSERT_KEYWORD
package cc;

import org.apache.jasper.tagplugins.jstl.core.Catch;

import java.lang.Exception;

public class BadWhitespaceAssertKeyword {
    public void goodTest() {
        assert (true);
    }

    public void badTest () {
        assert(true); // @violation
    }
}