package cc;

public class DoNotUseDoWhile {
    public void test(boolean condition) {
        do {                // @violation
            // statement
        } while(condition);

        // statement
        while(condition) {
            // statement
        }
    }
}
