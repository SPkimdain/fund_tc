package security;

public final class DefineWrappersAroundNativeMethods {
    // Public native method
    public native void nativeOperation(byte[] data, int offset, int len); // @violation
    // Wrapper method that lacks security checks and input validation
    public void doOperation(byte[] data, int offset, int len) {
        nativeOperation(data, offset, len); // @violation
    }
    static {
        // Load native library in static initializer of class
        System.loadLibrary("NativeMethodLib");
    }
}