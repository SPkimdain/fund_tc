import java.io.File;
import java.io.FileOutputStream;
import java.util.ArrayList;
import java.util.List;

public class Metric {

    // Anonymous class
    public static void anonclass(String[] str) {
        new Thread() {
            private String message = null;

            Thread initialise(String message) {
                this.message = message;
                return this;
            }

            public void run() {
                System.out.println(message);
            }
        }.initialise(str[0]).start();
    }

    public static int absoluteValue(int i) {
        excessiveIncoming();
        return (i < 0) ? -i : i;
    }

    // Primitive wrapper
    public static void primitive() { /* BUG - 14 outgoing calls */
        excessiveIncoming();
        List<Integer> li = new ArrayList<>();
        for (int i = 1; i < 50; i += 2)
            li.add(i);

        Integer i = new Integer(-8);

        int absVal = absoluteValue(i);
        System.out.println("absolute value of " + i + " = " + absVal);

        List<Double> ld = new ArrayList<>();
        ld.add(3.1416);

        double pi = ld.get(0);
        System.out.println("pi = " + pi);
    }

    // String
    static void printSong(Object stuff, int n) {
        excessiveIncoming();
        String plural = (n == 1) ? "" : "s";
        while (true) {
            System.out.println(n + " bottle" + plural + " of " + stuff + " on the wall,");
            System.out.println(n + " bottle" + plural + " of " + stuff + ";");
            System.out.println("You take one down " + "and pass it around:");
            --n;
            plural = (n == 1) ? "" : "s";
            if (n == 0) break;
            System.out.println(n + " bottle" + plural + " of " + stuff + " on the wall!");
            System.out.println();
        }
        System.out.println("No bottles of " + stuff + " on the wall!");
    }

    public static void autocloseExample(String[] args) { /* BUG - 11 outgoing calls */
        excessiveIncoming();
        try (FileOutputStream auto = new FileOutputStream(new File("")); ThrowBlocks.Throw ss = ThrowBlocks.Throw.throwException(true); ThrowBlocks.AutoClose auto2 = new ThrowBlocks.AutoClose()) {

        } catch (Exception e) {
            System.out.println("exception");
        }
    }

    public static void main(String[] args) {
        excessiveIncoming();
        System.out.println("Hello, World!");
        anonclass(new String[]{"abc", "def"});
    }

    public static void excessiveIncoming() { /* BUG - 9 incoming calls */
        excessiveIncoming();
    }

    public void callee1() {
        excessiveIncoming();
    }

    public void callee2() {
        excessiveIncoming();
    }

    public void callee3() {
        excessiveIncoming();
    }

    public void callee4() {
    }

    public void callee5() {
    }

    public void excessiveOutgoing() { /* BUG - 11 outgoing calls */
        autocloseExample(new String[]{"abc", "def"});
        printSong("obj", 4);
        anonclass(new String[]{"abc", "def"});
        primitive();
        absoluteValue(1);
        excessiveIncoming();
        callee1();
        callee2();
        callee3();
        callee4();
        callee5();
    }

    // autoclose example
    static class AutoClose implements AutoCloseable {

        public AutoClose() {
            System.out.println("constructor");
        }

        @Override
        public void close() throws Exception {
            System.out.println("close");
        }
    }

    static class Throw implements AutoCloseable {

        public static ThrowBlocks.Throw throwException(boolean is) throws Exception {
            if (is) {
                throw new Exception("throw");
            }
            return new ThrowBlocks.Throw();
        }

        @Override
        public void close() throws Exception {
            System.out.println("throw close");
        }
    }

}