package CWE1335.CWE1335_D;

import CWE1335.functions;

public class cwe1335_d {
    public static void main(String[] args) {
        int result1 = 1 << 32; //@violation
        int result2 = 1 >> 32; //@violation
        int result3 = 1 >>> 32; //@violation


        System.out.println("Result: " + result1);
        System.out.println("Result: " + result2);
        System.out.println("Result: " + result3);

        //tc
        int result4 = functions.shiftLeft(1, 32); //@violation
        int result5 = functions.shiftRight(1, 32); //@violation
        int result6 = functions.shiftRightUnsigned(1, 32); //@violation


        System.out.println("Result: " + result4);
        System.out.println("Result: " + result5);
        System.out.println("Result: " + result6);


    }
}
