package src.test.java.pmd;

public class AvoidCatchingThrowable {
    public void fun1(int a) {
        try {
            // do something
        } catch (Throwable th) {  // @violation

        }
    }

    public void fun2() {
        int c;

        try {
            c = 4 / 0;
        } catch(ArithmeticException e) {
            c = -1;
        }
    }
}