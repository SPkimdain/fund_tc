package nd;

/**
 * Writer: Gyuhang Shim
 * Date: 6/28/12
 */
public class NullCheckTest {
    public String oldInfo, newInfo;

    public void test(String str, String str2, String str3) {
        int a = 0;
        if (str != null && str2 == null && str3 != null)
            a = 10;
        str.toLowerCase(); /* BUG */
    }

    public void test2() {
        int a = -1;
        if (oldInfo != null && newInfo != null)
            a = 10;
        oldInfo.toUpperCase(); /* BUG */
    }

    public void test3(String str) {
        int a = str == null ? -1: 5;

        str.toLowerCase(); /* BUG */
    }

    public void test4(String str) {
        if(str == null) System.exit(-1);

        str.toLowerCase();
    }
}
