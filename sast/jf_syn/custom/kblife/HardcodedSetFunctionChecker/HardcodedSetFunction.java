
public class HardcodedSetFunction {
    public void callItem() {
        header.setTskUsrEmpno("");               // @violation
        header.setComUserId("");               // @violation
        header.setUserIP("");                    // @violation
        header.setRsdn("");                      // @violation
        header.setSiteUserId("");                // @violation

        standardHeader.setTskUsrEmpno(null);     // @violation
        standardHeader.setComUserId(null);       // @violation
        standardHeader.setUserIP(null);          // @violation
        standardHeader.setRsdn(null);            // @violation
        standardHeader.setSiteUserId(null);      // @violation

        header.setTskUsrEmpno("TA023");         // @violation
        header.setComUserId("TA023");           // @violation
        header.setUserIP("TA023");              // @violation
        header.setRsdn("TA023");                // @violation
        header.setSiteUserId("TA023");          // @violation

        String a = "TA023";
        header.setTskUsrEmpno(a);
        header.setComUserId(a);
        header.setUserIP(a);
        header.setRsdn(a);
        header.setSiteUserId(a);
    }
}
