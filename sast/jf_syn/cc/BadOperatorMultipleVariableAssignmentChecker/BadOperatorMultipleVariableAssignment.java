package cc;

public class BadOperatorMultipleVariableAssignment {
    public int get(int x) {
        return x;
    }

    private int method1() {
        // Do something ...
        return 1;
    }

    private int method2() {
        // Do something ...
        return 2;
    }

    private void method3(int x, int y) {
        // Do something ...
    }

    public void func() {
        int x, y, z;
        x = y = 1; // @violation
        x = (y = 2); // @violation
        x = ((y = 3)); // @violation
        x = y = z = get(1); // @violation 2
        x = (int)(y = 2); // @violation
        x = 1 + (z = 2); // @violation
        if((x = method1()) + (y = method2()) == 10) { // @violation
            // Do something ...
        }
        method3(x = method1(), y = method2()); /* SAFE */
    }
    Comparator<Int> lambdaFunc = () -> {
        int x, y, z;
        x = y = 1; // @violation
        x = (y = 2); // @violation
        x = ((y = 3)); // @violation
        x = y = z = get(1); // @violation 2
        x = (int)(y = 2); // @violation
        x = 1 + (z = 2); // @violation
        if((x = method1()) + (y = method2()) == 10) { // @violation
            // Do something ...
        }
    };
}
