package pmd;

public class UseNotifyAllInsteadOfNotify {
    void testCase1() {
        notify(); // @violation
    }

    void testCase2() {
        x.notify(); // @violation
    }

    void testCase3() {
        notifyAll(); /* correct */
    }

    void testCase4() {
        x.notifyAll(); /* correct */
    }
}