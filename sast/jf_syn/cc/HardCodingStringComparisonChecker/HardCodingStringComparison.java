package cc;

import java.lang.String;

public class HardCodingStringComparison {

    public static final String stringConst = "abcde";
    public static final String anotherConst = "fghij";

    public String getString() {
        // Do something ...
    }

    public void func(String k) {
        if("abcde".equals(k)) { // @violation
            // Do something ...
        }

        if(stringConst.equals(k)) {
            // Do something ...
        }

        if("abcde".equals(getString())) { // @violation
            // Do something ...
        }

        if(stringConst.equals(getString())) {
            // Do something ...
        }

        if(getString().equals(stringConst)) { // @violation
            // Do something ...
        }

        if(getString().equals(k)) {
            // Do something ...
        }

        if(stringConst.equals(getString() + "abcdef")) { // @violation
            // Do something ...
        }

        if(getString().equals(stringConst + anotherConst)) { // @violation
            // Do something ...
        }

        if((stringConst + "abcde").equals(getString())) { // @violation
            // Do something ...
        }

        if((stringConst + anotherConst).equals(getString())) {
            // Do something ...
        }
    }
}
