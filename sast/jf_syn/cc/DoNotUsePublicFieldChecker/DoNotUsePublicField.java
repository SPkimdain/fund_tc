package cc;

import java.lang.String;

public class DoNotUsePublicField {
    private String privateField;
    public String publicField; // @violation

    private void privateMethod() {
        // Do something ...
    }

    public void publicMethod() {
        // Do something ...
    }
}
