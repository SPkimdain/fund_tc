package cc;

public class BadIfOnly {
    public void test(int x, int y, int z) {
        if (x > y) {
            if (z) {

            } // @violation
        } else if (y > z) {

        } else {

        }

        if (x < y) {

        } else if (y < z) {

        } // @violation
    }
}