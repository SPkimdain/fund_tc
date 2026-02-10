package basic;

import java.lang.Exception;
import java.sql.SQLException;

public class BadExceptionalCondition {

    public void func() {
        try {

        } catch(Exception e) {
            // Do something ...
        } // @violation

        try (StringBufferInputStream sbis = new StringBufferInputStream("abc")) {

        } catch(Exception e) {
            // Do something ...
        } // @violation
    }
}