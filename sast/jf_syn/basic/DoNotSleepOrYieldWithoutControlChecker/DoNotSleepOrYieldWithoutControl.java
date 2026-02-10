package basic;

import java.lang.InterruptedException;
import java.lang.Thread;

public class DoNotSleepOrYieldWithoutControl extends Thread {

    public void badFunc() {
        try {
            sleep(1000); // @violation
            yield(); // @violation
        } catch(InterruptedException ie) {
            // Do something ...
        }
    }

    public void goodFunc() {
        try {
            while(true) {
                sleep(1000); /* SAFE */
                yield(); /* SAFE */
            }
        } catch(InterruptedException ie) {
            // Do something ...
        }
    }
}