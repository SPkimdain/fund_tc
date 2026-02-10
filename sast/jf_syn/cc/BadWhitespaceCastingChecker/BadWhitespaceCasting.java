package cc;

public class BadWhitespaceCasting {
    public void byteFunc(byte b) {
        // Do something ...
    }

    public void func(int a) {
        byte b;
        b = (byte)/* commnet */a; 	// @violation
        b = (byte) a;
        b = (byte )a;				// @violation
        b = ( byte)a;				// @violation
        b = ( byte )a;				// @violation
        
        byteFunc((byte)a); 	// @violation
        byteFunc((byte) a);
        byteFunc(( byte)a);	// @violation
        byteFunc((byte )a);	// @violation
        byteFunc(( byte )a);	// @violation
    }
}
