package cc;

public class ConditionalOperationWithoutParenthesis {
    public boolean isZero(int x) {
        return x == 0;
    }
    public void func(int x, int y, boolean b) {
        int v;
        v = x >= 0 ? x : -x; // @violation
        v = isZero(x) ? x : -x; /* SAFE since there is no binary operation */
        v = x >= (y * 2) ? x : -x; // @violation
        v = b ? x : -x; /* SAFE */

        v = (x >= 0) ? x : -x;
    }
}
