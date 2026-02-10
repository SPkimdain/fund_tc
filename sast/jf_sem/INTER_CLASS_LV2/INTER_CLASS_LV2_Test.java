package inter_class_lv2;

/* inter class level 2 test */
public class INTER_CLASS_LV2_Test {
    public void safeTest() {
        String str = null;

        str = LV2_ClassLib.getString(); // str should not be null

        str.toUpperCase(); /* SAFE */
    }

    public void test() {
        String str = "abc";
        str = LV2_ClassLib.getNullString();
        str.toUpperCase(); /* BUG */
    }
}
