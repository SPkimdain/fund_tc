package cc;

public class Capital {
    public int good;

    private int Bad; // @violation

    public static final int CONST_TEST = 10;

    public static final int constTest = 20; // @violation

    private static int sTest = 30;

    private static int BAD_PRIVATE_STATIC = 40; // @violation

    public void testMethod(int TEST) { // @violation

    }
}