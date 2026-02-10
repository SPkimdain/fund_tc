package cc;

public class LoggerErrorInCatch {
    public void test() {
        try {
            // ...
        }
        catch (DataObjectException doEx) { // @violation
            // no logger.error()
        }

        try {
            // ...
        }
        catch (DataObjectException doEx) {
            logger.error("....");
        }
    }
}