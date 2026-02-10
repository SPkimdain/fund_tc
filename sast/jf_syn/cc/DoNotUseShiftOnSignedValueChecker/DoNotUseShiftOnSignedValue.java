package cc;

public class DoNotUseShiftOnSignedValue {

    public int iFunc() {
        int a;
        // Do something ...
        return a;
    }

    public char cFunc() {
        char c;
        // Do something ...
        return c;
    }

    public void test(int i, char c) {
        int iResult;
        char cResult;

        iResult = i << 2; // @violation
        cResult = c << 2;

        iResult = (char)i >> 2; /* SAFE */
        cResult = (int)c >> 2; // @violation

        iResult = iFunc() << 2; // @violation
        cResult = cFunc() << 2;

        iResult = (char)iFunc() >> 2; /* SAFE */
        cResult = (int)cFunc() >> 2; // @violation
    }
}