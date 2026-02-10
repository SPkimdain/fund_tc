package pmd;

public class doNotUseNPE {
    void testCase1() {
        try {
            /* do something*/
        } catch (NullPointerException npe) { // @violation

        }
    }

    void testCase2() {
        try {
            /* do something*/
        } catch (Exception e) { /* safe */
            throw new NullPointerException();
        }
    }
}