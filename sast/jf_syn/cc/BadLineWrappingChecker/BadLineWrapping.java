package cc;

import java.lang.System;

public class BadLineWrapping implements InterfaceA // @violation
                                      , InterfaceB,
                                        InterfaceC {

    int iField = 3;
    int // @violation
        wField = 3;
    int a,
        b = 3 // @violation
      , c,
        d;

    public enum Enum {
        AAA // @violation
      , BBB,
        CCC
    }

    public int array[][] = { {1 // @violation
                            , 2},
                             {3, 4} // @violation
                           , {5,
                              6} };

    private void func(int parma1, int param2,
                      int param3 // @violation
                    , int param4,
                      int // @violation
                      param5,
                      int param6) {

        int var = (param1 + param2 + // Comment // @violation
                   param3);

        int var2 = param1 + /* Comment */ // @violation
                   param2 + (param3 = (3))
                 + param4 + // @violation
                   param5 + param1
                   ;

        var = // @violation
            2 + // @violation
            5 + 7
          + 6;

        var2 += // @violation
             3 + 5
           + 6;

        int var3 = // @violation
            5;
        int var4
          = 6,
            var5 = // @violation
            7;

        func(1, 2 // @violation
           , 3 + 4,
             5 + // @violation
             6, 7);

        for(param1 = 2,
            param2 = 3 // @violation
          , param3 = 4;
            param1 < 2;
            param1++ // @violation
          , param2++,
            param3++) {
            // Do something ...
        }

        int var6 = (3 + 5)
                 + (4 + 6);

        int var7 = (3 // @violation
                  + 5) + (4 + 6);

        int var8 = (3 + 5)
                      + (4 + 6); // @violation

        int var9 = ((3 + 5) + (4 + 6)
                  + (2 + 5) + (1 + 7));
    }

    public void test(int a, int b) {
        int c, d, e, f;
        if ((a && b)
            || (c && d)     // @violation
            ||!(e && f)) {  // @violation
            int g;
        }
        if ((a && b)
                || (c && d)
                ||!(e && f)) {
            int g;
        }
    }
}
