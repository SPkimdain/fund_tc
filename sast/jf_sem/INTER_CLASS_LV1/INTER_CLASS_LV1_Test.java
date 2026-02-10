package inter_class_lv1;

/* inter class level 1 test
 OPT : -show_followers
*/
public class INTER_CLASS_LV1_Test {
    public void test () {
        String str = "abc";

        str = LV1_ClassA.getNullString();
        str.toUpperCase(); /* BUG */
    }

    public void test2() {
        String str = getSomeString();
        str.toUpperCase(); /* BUG */
    }
    public String getSomeString() { return null;}
}
