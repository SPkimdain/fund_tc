package security;

public class DirectUseOfUnsafeJNI {
    public native void testJNI();  // @violation
}