package nd;

import java.io.*;
import java.util.Random;

class ExceptionTest {
    void check(boolean isTrue, String msg) throws Exception {
        if(isTrue) {
            throw new Exception();
        }
    }
    void exceptionThrownByMethodTest() throws Exception {
        String x = null;
        check(x == null, "exception thrown!");
        x.toUpperCase();
    }

    Exception returnExpt(int x) {
        if(x > 0) return new Exception();
        else return new IOException();
    }
    void exceptionReturnTest() {
        Exception e = returnExpt(0);
        String x = null;
        try {
            throw e;
        } catch(IOException i) {
            System.out.println("IOException");
            x.toUpperCase(); /* BUG */
        } catch(Exception ex) {
            System.out.println("Exception");
            x.toUpperCase();
        }
    }
}