package cc;

import java.lang.System;

public class BadWhitespaceComma implements InterfaceA,InterfaceB, // @violation
                                           InterfaceC, InterfaceD {
    int a,b = 3 // @violation
        , c, d;

    public enum Enum {
        AAA, BBB ,CCC // @violation
    }

    public int array[][] = { {1,2}, // @violation
                             {3, 4}
                             , {5, 6} };

    private void func(int parma1 ,int param2, int param3, // @violation
                      int param4, int param5, int param6) {

        int va ,vb = 3 // @violation
            , vc, vd;

        func(0,1 ,2, 3,4, 5); /* SAFE */

        for(param1 = 2,param2 = 3 // @violation
            , param3 = 4, param4 = 5;
            param1 < 2;
            param1++, param2++,
            param3++ ,param4++) { // @violation
        }
    }
}
