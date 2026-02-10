package simple_inter;

public class SimpleInterTest {
    public void safeTest () {
        ClazzA clazzA = new ClazzA();

        int c = clazzA.getInt(); // c = 700
        String str = null;
        if (c > 0) {
            str = "abc";
        }
        str.toUpperCase(); /* SAFE */
    }

    public void safeTest2() {
        ClazzA clazzA = new ClazzA();
        String str = null;
        if (clazzA.getBoolean()) { // clazzA.getBoolean() = true
            str = "abc";
        }
        str.toUpperCase(); /* SAFE */
    }

    public void safeTest3() {
        ClazzA clazzA = new ClazzA();
        String str = null;
        if (clazzA.getSix() == 6) { // clazzA.getBoolean() = true
            str = "abc";
        }
        str.toUpperCase(); /* SAFE */
    }

    public void test() {
        ClazzA clazzA = new ClazzA();
        String str = "abc";
        if (clazzA.getFalse() == false) { // evaled true
            str = null;
        }
        str.toLowerCase(); /* BUG */
    }

    public void test2() {
        ClazzA clazzA = new ClazzA();
        String str = "abc";
        if (clazzA.getThree() == 3) { // evaled true
            str = null;
        }
        str.toLowerCase(); /* BUG */
    }

    public void test3() {
        ClazzA clazzA = new ClazzA();
        String str = "abc";
        if (clazzA.getSomeInt() == 3) { // clazzA.getSomeInt() = Unknown (ATop), try this pass
            str = null;
        }
        str.toLowerCase(); /* BUG */
    }
}
