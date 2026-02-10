package cc;

public class BadNameTooLong {
    private int shortVariable;
    private int longVariableDoNotUseTooLongNameInSourceCodes; // @violation

    public void shortMethod() {
        // Do something ...
    }

    public void longMethodDoNotUseTooLongNameInSourceCodes() { // @violation
        // Do something ...
    }

    public void longParamMethod(int longParamDoNotUseTooLongNameInSourceCodes) { // @violation
        // Do something ...
    }

    public void func() {
        int shortLocal;
        int longLocalDoNotUseTooLongNameInSourceCodes; // @violation
    }

    public class shortClass {
        // Something in here ...
    }

    public class longClassDoNotUseTooLongNameInSourceCodes { // @violation
        // Something in here ...
    }
}