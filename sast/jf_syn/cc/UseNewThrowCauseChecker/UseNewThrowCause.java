package cc;

public class UseNewThrowCause {
    public void test1() {
        try {
            // ...
        }
        catch(DataObjectException doEx) { // @violation
            // handling exception
        }
    }

    public void test2() {
        try {
            // ...
        }
        catch(DataObjectException doEx) {
            // handling exception
            CommUtil.newThrowCause(logger, "...");
        }
    }
}
