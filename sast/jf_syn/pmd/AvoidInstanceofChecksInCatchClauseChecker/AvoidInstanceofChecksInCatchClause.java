package src.test.java.pmd;

public class AvoidInstanceofChecksInCatchClause {

    void fun() {
        try {
            // do something
        } catch (Exception ee1) {
            if (ee1 instanceof IOException) { // @violation
                cleanup();
            }
        }

        try {
            // do something
        } catch (IOException ee2) {
            if ((Exception)ee2 instanceof Exception) { // @violation
                cleanup();
            }
        }
    }
}
