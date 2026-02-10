package pmd;

import java.lang.System.out;
import java.lang.System.err;

public class SystemPrintln {
    void testCase1() {
        System.out.println(); // @violation
        System.out.printf(); // @violation
        System.out.print(); // @violation
    }

    void testCase2() {
        System.err.println();  // @violation
        System.err.printf();  // @violation
        System.err.print();  // @violation
    }

    void testCase3() {
        out.println(); // @violation
        out.printf(); // @violation
        out.print(); // @violation
    }

    void testCase4() {
        err.println(); // @violation
        err.printf(); // @violation
        err.print(); // @violation
    }
}