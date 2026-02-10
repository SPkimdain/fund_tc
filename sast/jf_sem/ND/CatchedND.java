package nd;

public class CatchedND {
    void noND() {
        String x = null;
        try {
            x.toUpperCase();
        } catch (Exception e) {
            /* ignore ND */
        }
    }
    void noNDTrigger(String x) {
        try {
            x.toUpperCase();
        } catch (Exception e) {
            /* ignore ND */
        }
    }
    void ndTrigger(String x) {
        x.toUpperCase();
    }
    void useNDTrigger() {
        String x = null;
        noNDTrigger(x);
        ndTrigger(x); /* BUG */
        try {
            ndTrigger(x);
        } catch (Exception e) {
            /* ignore ND */
        }
    }
}
