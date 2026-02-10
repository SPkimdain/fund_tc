package scaffold.nd.nullness;

public class NullNessTest {
    public void test (NullNessTestLib lib) {
        String str = null;
        int a = lib.isNull(str); // a should be 1
        if (a != 1) {
            str.toLowerCase(); /* BUG */
        }
    }
}