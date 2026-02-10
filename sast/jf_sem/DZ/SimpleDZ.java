package dz;

public class SimpleDZ {
    void foo() {
        int x = 10;
        int y = 20;
        int z = 30;
        z = z / (y - x - x); /* BUG */
    }
}
