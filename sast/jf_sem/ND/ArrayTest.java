package nd;

/**
 * Writer: Gyuhang Shim
 * Date: 6/27/12
 */
public class ArrayTest {

    public String [] getArray(int b) {
        if (b > 0) {
            String [] result = {"a", "b"};
            return result;
        }
        return null;
    }

    public void test(int a) {
        int length = getArray(a).length; // 버그 검출 못함
        int hash = getArray(a).hashCode(); /* BUG */
        String str = getArray(a)[0]; // 버그 검출 못함
    }

    public String getString(int c) {
        if (c > -1) {
            return "abc";
        }
        return null;
    }
    public void test2(int a) {
        String str = getString(a);
        str.toLowerCase(); /* BUG */
    }

    public Point getPoint(int x, int y) {
        if (x > y) {
            return new Point(x,y);
        }
        return null;
    }
    public void test3(int a, int b) {
        Point p = getPoint(a, b);
        int x = p.x; /* BUG */
        int y = p.getY(); /* BUG */
    }
    class Point {
        public int x;
        public int y;

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
