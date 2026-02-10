public class LoginView {
    private int a;			/* Safe */
    private long b;		    /* Safe */
    private short c;		// @violation
    private byte d;		    // @violation
    private char e;		    // @violation
    
    public void foo(int a) {}	/* Safe */
    public void foo(long b) {}		/* Safe */
    public void foo(short c) {}		// @violation
    public void foo(byte d) {}		// @violation
    public void foo(char e) {}		// @violation
    
    public void foo2() {
    	int a;			/* Safe */
        long b;		    /* Safe */
        short c;		// @violation
        byte d;		    // @violation
        char e;		    // @violation
    }
}
