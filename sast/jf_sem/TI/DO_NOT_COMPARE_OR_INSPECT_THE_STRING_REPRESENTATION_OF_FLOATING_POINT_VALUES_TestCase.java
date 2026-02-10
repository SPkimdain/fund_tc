package ti;

import java.math.BigDecimal;

class DO_NOT_COMPARE_OR_INSPECT_THE_STRING_REPRESENTATION_OF_FLOATING_POINT_VALUES_TestCase {
    void test() {
        int i = 1;
        String s = Double.valueOf(i / 1000.0).toString();
        if (s.equals("0.001")) { /* BUG */
            // ...
        }
    }
    void test2() {
        int i = 1;
        String s = Double.valueOf(i / 1000.0).toString();
        s = s.replaceFirst("[.0]*$", "");
        if (s.equals("0.001")) { /* BUG */
            // ...
        }
    }
    void testSafe() {
        int i = 1;
        BigDecimal d = new BigDecimal(Double.valueOf(i / 1000.0).toString());
        if (d.compareTo(new BigDecimal("0.001")) == 0) {
            // ...
        }
    }
}