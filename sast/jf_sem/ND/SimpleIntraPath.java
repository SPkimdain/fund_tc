package nd;

import java.util.Random;

public class SimpleIntraPath {
    int rnd = new Random().nextInt(); /* BUG */
    void impossiblePath1() {
        String x = "asdf";
        String y = "zxcv";
        if(rnd > 10 && rnd < 0) x = null;
        x.toString();
    }
    void impossiblePath2() {
        String x = "asdf";
        String y = "zxcv";
        if(rnd > 0) x = null;
        if(rnd > -10) x = "back";
        x.toString();
    }
   void impossiblePath3() {
        String x = "asdf";
        String y = "zxcv";
        if(rnd == 0 && rnd != 0) x = null;
        x.toString();
    }
    void reassignmentWith2Branch() {
        String x = "zxcv";
        String y = "asdf";
        if(rnd > 10) x = null;
        if(rnd > 20) x = "asdf";
        x.toString(); /* BUG */
    }
}