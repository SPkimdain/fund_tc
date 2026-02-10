//IMPROPER_RETURN_STATEMENT
package cc;

public class ImproperReturnStatement {

    public int func(boolean condition, int intX, int intY) {
        if(condition) {
            return intX;    /* SAFE */
        } else if(intY == 1) {
            return (intY > 0 ? intY : 0); /* SAFE */
        } else {
            return 1;   /* SAFE */
        }

        if(intX == 0) {
            return (intX);  // @violation
        } else if(intY == 0) {
            return (test());    // @violation
        } else {
            return test();  /* SAFE */
        }

        return intY > 0 ? intY : 0; // @violation
    }

    public int test() {
        return (1); // @violation
    }

    Consumer<Integer> lambdaFunc4 = (int x) -> {
        if (x == 0) {
            return x;   /* SAFE */
        } else if (x == 1) {
            return (x); // @violation
        } else if (x == 2) {
            return test();
        } else {        /* SAFE */
            return (test()); // @violation
        }

    };
}
