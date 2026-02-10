package inter_class_lv0;

/* inter class level 0 test */
public class INTER_CLASS_LV0_Test {
    public void test() {
        int a = 3;
        int b = 5;

        String str = "abc";
        if (a + b > 7) {
            str = null;
        }

        str.toUpperCase(); /* BUG */
    }
}
