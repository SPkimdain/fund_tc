package nd;

/**
 * Writer: Gyuhang Shim
 * Date: 7/3/12
 */
public class GlobalVarTest {
    public String name = "abc";

    public void test(int x, int y) {
        String str = null;
        if (x > y) {
            str = name;
            name = null;
        }
        // TODO: 아래 케이스에서 FORWARD_NULL 알람이 발생 하고 있다. 발생 안하게 수정
        if (str != null) {
            if (x > 0) {
                if (y > 0) {
                    foo(str); /* NOT BUG */
                }
            }
        }
    }

    public void foo(String str) {
        str.toLowerCase();
    }
}
