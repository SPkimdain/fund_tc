package nd;

/**
 * Writer: Gyuhang Shim
 * Date: 6/27/12
 */

/* OPT : -show_followers */

public class SwitchTest {

    public void test(int a) {
        String str = null;
        switch(a) {
            case 1: {
                str = "abc";
            }
            case 2: {
                str.toLowerCase(); /* BUG */
            }
            case 3: {
                str = "def";
            }
        }
        str.toLowerCase(); /* BUG */
    }
}
