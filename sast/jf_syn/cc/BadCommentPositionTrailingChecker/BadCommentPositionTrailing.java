package cc;

public class BadCommentPositionTrailing {

    public A A;
    public int iField;

    public String sField;

    public void func() { // Trailing comment
        A A;
        int a = 0;
        int b = 0;
        int c = 0; // Bad
                 // Trailing indentation // @violation

        int d = 0; // Good
                   // Trailing indentation

        int e = 0;// Bad Trailing comment // @violation

        int test = 0;   // No indentation check since it is no trailing comment
        int test2= 0;   // No indentation check since it is no trailing comment
    }
}
