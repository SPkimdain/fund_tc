package src.test.java.pmd;

public class AvoidUsingNativeCode {

    public void someJNIClass() {
        System.loadLibrary("nativelib"); // @violation
    }

    static {
        System.loadLibrary("nativelib"); // @violation
    }

    public void invalidCallsInMethod() throws SecurityException, NoSuchMethodException {
        System.loadLibrary("nativelib"); // @violation
    }
}