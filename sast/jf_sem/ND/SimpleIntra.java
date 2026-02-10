package nd;

import java.util.Random;

public class SimpleIntra {
    int rnd = new Random().nextInt(); /* BUG */
    void basic() {
        String x = null;
        x.toString(); /* BUG */
    }
    void ifTrueBranch() {
        String x = null;
        String y = null;
        if(rnd > 10) x.toString(); /* BUG */
    }
    void ifFalseBranch() {
        String x = null;
        String y = null;
        if(rnd > 10) x = "asdf";
        else y.toString(); /* BUG */
    }
    void autoBoxedBoolean() {
        Boolean x = true;
        Boolean y = false;
        String z = null;
        if(x && y) {
            z.toString();
        }
    }
    void reassignment() {
        String x = null;
        String y = "asdf";
        x = "asdf";
        x.toString();
    }
    void reassignmentWithBranch() {
        String x = null;
        String y = "asdf";
        if(rnd > 10) x = "asdf";
        x.toString(); /* BUG */
    }
}