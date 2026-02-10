package cc;

public abstract class ComplyWithModifierOrder {
    private abstract synchronized void test1();

    final public static void test2() { // @violation

    }

    public static final test2good() {

    }

    synchronized public final int test3() { // @violation
        return 0;
    }

    public final synchronized test3good() {

    }

    native final public void test4(); // @violation

    final public native void test4bad2(); // @violation

    public final native void test4good();
}