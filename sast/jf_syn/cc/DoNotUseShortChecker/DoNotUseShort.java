package cc;

public class DoNotUseShort {
    private int gIValue;
    private short gSValue; // @violation

    private void iFunc(int iParam) {
        int lIValue;
        // Do something ...
    }

    private void sFunc(short sParam) { // @violation
        short lSValue; // @violation
        // Do something ...
    }
}
