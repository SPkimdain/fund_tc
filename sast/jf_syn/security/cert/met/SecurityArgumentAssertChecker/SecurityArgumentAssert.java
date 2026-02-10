public class SecurityArgumentAssert {
    public static int getAbsAdd(int x, int y) {
        assert x != Integer.MIN_VALUE;              // @violation
        assert y != Integer.MIN_VALUE;              // @violation
        int absX = Math.abs(x);
        int absY = Math.abs(y);
        assert (absX <= Integer.MAX_VALUE - absY);
        return absX + absY;
    }
}