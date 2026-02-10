package nd;

import java.util.Random;

public class SimpleInterPath {
    int rnd = new Random().nextInt(); /* BUG */
    void argLt10Bug(int x) {
        String s = null;
        if(x > 10) s.toString(); /* BUG */
        // now, we don't wait until unknown constraints are fully resolved before issuing alarms
    }
    void trig() {
        if(rnd < 5) argLt10Bug(rnd);
    }
}