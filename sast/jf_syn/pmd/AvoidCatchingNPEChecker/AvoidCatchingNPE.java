package pmd;

public class AvoidCatchingNPE {
    void testCase1() {
        try {
            /* do something*/
        } catch (NullPointerException npe) { // @violation
            /* do something*/
        }
    }

    void testCase2() {
        try {
            /* do something*/
        } catch (Exception e) { /* safe */
            /* do something*/
        }
    }

    void testCase3() {
        try {
            /* do something*/
        } catch (IOException ioe) { /* safe */
            /* do something*/
        }
    }
}