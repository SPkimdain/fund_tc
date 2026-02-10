package pmd;

public class AvoidLosingExceptionInformation {
    void testCase1() {
        try {
            // do something
        } catch (IOException se) {
            se.getMessage(); // @violation
            se.getLocalizedMessage(); // @violation
            se.getCause(); // @violation
            se.getStackTrace(); // @violation
            se.toString(); // @violation
        }
    }
}