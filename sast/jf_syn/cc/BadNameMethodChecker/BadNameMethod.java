package cc;

public class Capital {
    public static final int Good;

    public void doIt() {}
    private void DoIt() {}      // @violation
    public void Do() {}         // @violation
    protected void isThat() {}
    public String methodName() {}
}
