public class LoginView {
    private int a;			/* Safe */
    private long b;		    /* Safe */
    private float c;		// @violation
    private double d;		    // @violation
    private Bigdecimal e;		    /* Safe */
    
    public void foo(int a) {}	/* Safe */
    public void foo(long b) {}		/* Safe */
    public void foo(float c) {}		// @violation
    public void foo(double d) {}		// @violation
    public void foo(Bigdecimal e) {}		/* Safe */
    
    public void foo2() {
    	int a;			/* Safe */
        long b;		    /* Safe */
        float c;		// @violation
        double d;		    // @violation
        Bigdecimal e;		    /* Safe */
    }
}
