package pmd;

import java.math.BigDecimal;


public class AvoidDecimalLiteralsInBigDecimalConstructor {
    void testCase1() {
        BigDecimal bd = new BigDecimal(1); /* safe */
    }

    void testCase2() {
        float a = 1.2f;
        BigDecimal bd = new BigDecimal(a); // @violation
    }

    void testCase3() {
        double a = 1.2;
        BigDecimal bd = new BigDecimal(a); // @violation
    }

    void testCase4() {
        BigDecimal bd = new BigDecimal(1.2f); // @violation
    }

    void testCase5() {
        BigDecimal bd = new BigDecimal(1.2); // @violation
    }

    void testCase6() {
        String str = "1.233";
        BigDecimal bd = new BigDecimal(str); /* safe */
    }

    void testCase7() {
        double a = 1.2;
        BigDecimal bd;
        bd = new BigDecimal(a); // @violation
    }

    void testCase8() {
        BigDecimal bd = new BigDecimal((float) 1); // @violation
    }

    void testCase9() {
        int a = 1;
        BigDecimal bd = new BigDecimal((double) a); // @violation
    }

    void testCase10() {
        int a = 1;
        double b = 0.2;

        BigDecimal bd = new BigDecimal(a + b); // @violation
    }

    void testCase11() {
        BigDecimal bd = BigDecimal.valueOf(1.2); /* safe */
    }

    void testCase12() {
        BigDecimal bd;
        bd = BigDecimal.valueOf(1.2); /* safe */
    }
}