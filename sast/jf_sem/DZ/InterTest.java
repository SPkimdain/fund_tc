package dz;

public class InterTest {
    void foo(int p) {
        int x = 0;

        bar(x); /* BUG */

        if(p == 0) {
            System.out.println("dummy");
        }

        bar(p); /* BUG */
    }
    void bar(int x) {
        int z = 10 / x;
        System.out.println("dummy");
    }
    void bar() {
        int x = 20;
        int y = 30;
        double ratio = getRatio(x, y); /* BUG */
    }

    public double getRatio(int a, int b) {
        int c = a + b + 100;

        return c / (a - b + 10);
    }
}
