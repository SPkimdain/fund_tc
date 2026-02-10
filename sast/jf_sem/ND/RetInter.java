package nd;

/* OPT : -show_followers */

public class RetInter {
    String ret3() {
        String x = null;
        String y = "asdf";
        return x;
    }
    String ret2() {
        return ret3();
    }
    String ret1() {
        return ret2();
    }
    void trig() {
        String x = ret1();
        String y = "zxcv";
        x.toString(); /* BUG */

        ((String) ((Object) ret1())).toUpperCase(); /* BUG */
    }
}