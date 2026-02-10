package pmd;

public class doNotUseNPE {
    void testCase1() {
        try {
            /* do something*/
        } catch (Exception e) { /* safe */
            NullPointerException a = new NullPointerException();
            throw a;
            throw new NullPointerException();
        }
    }

}