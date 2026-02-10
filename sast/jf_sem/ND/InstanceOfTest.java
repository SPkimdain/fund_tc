package nd;

public class InstanceOfTest {
    public static void main(String [] args) {
        String str = null;
        String str2 = null;
        String nonNullStr = "abcdefg";

        if (str instanceof String) {
            str.toUpperCase(); /* NOT BUG */
            System.out.println("haha");
        } else {
            str.toUpperCase(); /* BUG */
            System.out.println("hoho");
        }

        if (nonNullStr instanceof String) {
            str2.toUpperCase(); /* BUG */
        }
    }
}
