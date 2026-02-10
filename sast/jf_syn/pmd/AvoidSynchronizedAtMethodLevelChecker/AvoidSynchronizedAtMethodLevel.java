package pmd;

public class AvoidSynchronizedAtMethodLevel {
    synchronized void testCase1() { // @violation

    }

    void testCase2() { /* correct */
        synchronized (this) {

        }
    }

    public synchronized void testCase3() { // @violation

    }

    public void testCase4() { /* correct */
        synchronized (this) {

        }
    }
}