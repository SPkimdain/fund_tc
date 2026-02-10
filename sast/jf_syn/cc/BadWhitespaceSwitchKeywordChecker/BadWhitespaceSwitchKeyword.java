// WHITESPACE.SWITCH_KEYWORD
package cc;

import org.apache.jasper.tagplugins.jstl.core.Catch;

import java.lang.Exception;

public class BadWhitespaceSwitchKeyword {
    public void goodTest() {
        switch (cnt) {
            // Do something ...
        }
    }

    public void badTest () {
        switch(cnt) { // @violation
            // Do something ...
        }
    }
}