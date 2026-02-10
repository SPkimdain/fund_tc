package src.test.java.pmd;

import java.lang.AssertionError;

public class AvoidRethrowingException {
    public void bar1() {
        try {
            // do something
        } catch (Exception se) { // @violation
            throw se;
        }
    }
    public void bar2() {
        try {

        } catch (InterruptedException ie) { /* OK */
            throw new AssertionError(ie);
        }
    }
}