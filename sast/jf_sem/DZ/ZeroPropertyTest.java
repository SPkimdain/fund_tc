package dz;

public class ZeroPropertyTest {
    void foo(int x) {
        if(x == 0) {
            System.out.println("I'm zero");
        }
    }
    void bar(int x) {
        foo(x);
        int y = 10 / x; /* BUG */
    }
}
