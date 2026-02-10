package basic;

import javax.servlet.ServletRequest;

public class PasswordManagementHeapInspection {
    private String pw = "password";

    public void passwordManagementHeapInspection(ServletRequest request) throws Exception {
        String pw = request.getParameter(this.pw);
        String var = "var string.";

        if(pw == null || pw.contains("<")) {
            System.out.println("Bad input.");
        } else {
            String hpw = new String(pw); // @violation
            hpw = new String(pw.toLowerCase() + var);
            hpw = new String(pw + ":" + var); // @violation
            System.out.println(hpw);
        }
    }
}
