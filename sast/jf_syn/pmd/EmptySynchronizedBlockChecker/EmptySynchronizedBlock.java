package pmd;

public class EmptySynchronizedBlock {
    void testCase1() {
        synchronized (this) { // @violation

        }
    }

    void testCase2() {
        synchronized (this) { /* safe */
            int a = 1;
        }
    }

    void testCase3() {
        synchronized (this) { // @violation
            ;;;
        }
    }

    void testCase4() {
        synchronized (this) { // @violation
            {

            }

            {

            }
        }
    }

    void testCase5() {
        synchronized (this) { /* safe */
            {

            }

            int a = 1;
        }
    }
}