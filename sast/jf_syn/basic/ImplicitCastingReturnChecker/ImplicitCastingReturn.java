package basic;

public class ImplicitCastingReturn {

    public int iFunc() {
        // Do something ...
        return 0;
    }

    public double dFunc() {
        // Do something ...
        return 0.0;
    }

    public int iReturnFunc(int cond, int pi, double pd, int[] ai, double[] ad) {
        int i;
        double d;
        Integer ci;
        Double cd;

        switch(cond) {
        case 0:
            return pi;
        case 1:
            return pd; // @violation
        case 2:
            return ci;
        case 3:
            return cd; // @violation
        case 4:
            return iFunc();
        case 5:
            return dFunc(); // @violation
        case 6:
            return i + d; // @violation
        case 7:
            return ai[0];
        case 8:
            return ad[0]; // @violation
        case 9:
            return (double)i; // @violation
        case 10:
            return (int)d;
        default:
             break;
        }
    }

    public double dReturnFunc(int cond, int pi, double pd, int[] ai, double[] ad) {
        int i;
        double d;
        Integer ci;
        Double cd;

        switch(cond) {
        case 0:
            return pi; // @violation
        case 1:
            return pd;
        case 2:
            return ci; // @violation
        case 3:
            return cd;
        case 4:
            return iFunc(); // @violation
        case 5:
            return dFunc();
        case 6:
            return i + d;
        case 7:
            return ai[0]; // @violation
        case 8:
            return ad[0];
        case 9:
            return (double)i;
        case 10:
            return (int)d; // @violation
        default:
            break;
        }
    }

    public double patternReturnFunc1(int pi) {
        return switch (pi) {
            case Integer i -> i;    // @violation
            case Double d -> {
                String s = "nop";
                d;
            }
            case null -> 1;
            default        -> String.format("Object %s", obj);
        };
    }

    public int patternReturnFunc2(double pd) {
        return switch (pd) {
            case Integer i -> i;
            case Double d -> d;     // @violation
            default        -> String.format("Object %s", obj);
        };
    }

    public int patternReturnFunc3(int pi) {
        return switch (pi) {
            case Integer i -> i;
            case Double d -> {    // @violation
                String s = "nop";
                d;
            }
            case null -> 1;
            default        -> String.format("Object %s", obj);
        };
    }
}
