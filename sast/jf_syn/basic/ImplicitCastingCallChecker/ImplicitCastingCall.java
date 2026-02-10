package basic;

import java.lang.Double;
import java.lang.Integer;
import java.lang.Long;

public class ImplicitCastingCall {

    private void iFunc(int a) {
        // Do something ...
    }

    private void dFunc(double d) {
        // Do something ...
    }

    private int getInt() {
        // Do something
        return 0;
    }

    private double getDouble() {
        // Do someething
        return 0.0;
    }

    public void badFunc() {
        int i;
        long l;
        double d;
        Integer ci;
        Long cl;
        Double cd;

        iFunc(d);
        iFunc(i+getDouble());
        iFunc((int)(cd+i));
        dFunc(i); // @violation
        dFunc(getInt()+d);
        dFunc((int)(d+ci)); // @violation
        dFunc(i+l); // @violation
        dFunc(l+cl); // @violation
    }
}