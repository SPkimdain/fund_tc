package cc;

import java.lang.Object;

public class DoNotUseAdjacentBinaryOperator {
    public void func(Object e, Object f) {
        if(e instanceof Object) {
            // Do something ...
        }

        if(e!= f) { // @violation
            f=e; // @violation
        }
    }

    public void func2(int a, int b, int c) {
        b = c >>>a; // @violation
        a+=b; // @violation
        a += (b+c) + a; // @violation
    }

    public void func3(boolean x, boolean y) {
        y = x||y; // @violation
        x = (x&y) ^ x; // @violation
    }

    public void func4(boolean x, boolean y) {
        y = x/* Comment */ /* Comment */& y; /* SAFE */
        x = x & y /* Comment */^ x; /* SAFE */
    }

    public void func5(boolean x, boolean y) {
        y = !x  ?  x  : /* Comment */ y; // @violation 2
        y = !x ? x/* Comment */:(y); // @violation
    }
}
