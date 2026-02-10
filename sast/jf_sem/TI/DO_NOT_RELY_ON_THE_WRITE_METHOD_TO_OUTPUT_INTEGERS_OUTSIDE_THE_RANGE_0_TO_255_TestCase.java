package ti;

class DO_NOT_RELY_ON_THE_WRITE_METHOD_TO_OUTPUT_INTEGERS_OUTSIDE_THE_RANGE_0_TO_255_TestCase {
    void test(String x) {
        // Any input value > 255 will result in unexpected output
        System.out.write(Integer.valueOf(x)); /* BUG */
        System.out.flush();
    }
    void testSafe(String x) {
        // Perform range checking
        int value = Integer.valueOf(x);
        if (value < 0 || value > 255) {
            throw new ArithmeticException("Value is out of range");
        }

        System.out.write(value);
        System.out.flush();
    }
}