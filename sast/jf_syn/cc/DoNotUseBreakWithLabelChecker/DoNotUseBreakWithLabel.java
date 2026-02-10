package cc;

public class DoNotUseBreakWithLabel {
    public boolean func(boolean condition) {
        // Do something ...
        return condition;
    }

    public void bad(boolean condition) {
        L1: while(true) {
            if(condition) {
                break L1; // @violation
            }
        }
    }

    public void good(boolean condition) {
        while(true) {
            if(func(condition)) {
                break; /* SAFE without label */
            }
        }
    }
}
