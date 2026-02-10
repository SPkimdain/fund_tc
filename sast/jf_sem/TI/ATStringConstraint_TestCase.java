package ti;

public class ATStringConstraint_TestCase {
    public void bar(String s) {
        String str = s+"abc";
        String x = null;
        if (str != null) {
            x = "hello";
        }
        x.toUpperCase();
        foo(str);
    }
    public String foo(String s) {
        String x = null;
        if (s != null) {
            x = "hello";
        }
        x.toUpperCase(); /* BUG */
        return x;
    }
}