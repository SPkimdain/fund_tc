package basic;

import java.lang.Double;
import java.lang.Integer;

public class ImplicitCastingAssignment {

    public int iFunc() {
        // Do something ...
        return 0;
    }

    public double dFunc() {
        // Do something ...
        return 0.0;
    }

    public void test(int pi, double pd, int[] ai, double[] ad) {
        int i;
        double d;
        Integer ci;
        Double cd;

        i = pi;
        i = pd; // @violation
        i = ci;
        i = cd; // @violation
        i = iFunc();
        i = dFunc(); // @violation
        i = i + d; // @violation
        i = ai[0];
        i = ad[0]; // @violation
        i = (double)i; // @violation
        i = (int)d;

        d = pi; // @violation
        d = pd;
        d = ci; // @violation
        d = cd;
        d = iFunc(); // @violation
        d = dFunc();
        d = i + d;
        d = ai[0]; // @violation
        d = ad[0];
        d = (double)i;
        d = (int)d; // @violation
    }
}