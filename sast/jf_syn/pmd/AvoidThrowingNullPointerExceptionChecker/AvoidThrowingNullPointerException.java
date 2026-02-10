package pmd;

public class AvoidThrowingNullPointerException {
    void testcase1() {
        throw new NullPointerException(); // @violation
    }
}