package ddc;

class DangerousDowncastTest {
    public static void workWith(int i) {
        byte b = (byte) i; /* BUG */
        // work with b
        System.out.println(b);
    }
    public static void workWithSafe(int i) {
        // check if i is within byte range
        if ((i < Byte.MIN_VALUE) || (i > Byte.MAX_VALUE)) {
            throw new ArithmeticException("Value is out of range");
        }

        byte b = (byte) i;
        // work with b
        System.out.println(b);
    }
    void test() {
        float i = Float.MIN_VALUE;
        float j = Float.MAX_VALUE;
        short b = (short) i; /* BUG */
        short c = (short) j; /* BUG */

        System.out.println(b);
        System.out.println(c);
    }
    void testSafe() {
        float i = Float.MIN_VALUE;
        float j = Float.MAX_VALUE;
        if ((i < Short.MIN_VALUE) || (i > Short.MAX_VALUE) ||
                (j < Short.MIN_VALUE) || (j > Short.MAX_VALUE)) {
            throw new ArithmeticException ("Value is out of range");
        }

        short b = (short) i;
        short c = (short) j;
        // other operations

        System.out.println(b);
        System.out.println(c);
    }
}