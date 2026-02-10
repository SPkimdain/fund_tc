public class OAM1001Q00 {
    private String l_CustName1;     // @violation
    private String g_CustName2;     // safe
    private String ga_CustName3;    // @violation
    private char[] ga_CustArray1;   // safe

    public void run() {
        String l_CustName4 = null;  // safe
        String g_CustName5 = null;  // @violation
        String la_CustName6 = null; // @violation
        char[] la_CustArray2 = null;// safe
    }
}