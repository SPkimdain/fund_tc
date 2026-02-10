package security;
import testcasesupport.KrdUtil;
public class MissingLoginControl {

    private void login() {
        for(int i=0; i<10; i++) {
            // Log-in here ...
        }
    }

    private void anotherlogin() {
        int i;
        while(i < 10) {
            // Log-in here ...
        }
    }

    private void another2login() {
        int i;
        do {
            // Log-in here ...
        } while(i < 10);
    }

    private void another3login() {
        for(;;) { // @violation
            // Log-in here ...
        }
    }

    private void another4login() {
        int i;
        while(((true))) { // @violation
            // Log-in here ...
            i++;
        }
    }

    public void func1() {
        login(); // @violation
    }

    public void func2() {
        for(int i=0; i<10; i++) {
            login();
        }
    }

    public void func3() {
        int i;
        while(i < 10) {
            login();
            i++;
        }
    }

    public void func4() {
        for(int i=0; true; i++) {
            login(); // @violation
        }
    }

    public void func5() {
        int i;
        while(((true))) {
            login(); // @violation
            i++;
        }
    }

    public void func6() {
        do {
            login(); // @violation
        } while(true);
    }

    public void bad(HttpServletRequest request, HttpServletResponse response) throws Throwable
    {
        String username = request.getParameter("username");
        String password = request.getParameter("password");

        /* FLAW */
        if (username == null || password == null || !KrdUtil.isAuthenticatedUser(username, password)) // @violation
        {
            response.getWriter().println("Invalid username, password<br/>");
            response.getWriter().println("<A href='/KRD_Debugging/KRD_214_Improper_Restriction_Of_Excessive_Authentication_Attempts.htm'>Login Again</A></body></html>");
        }
        else
        {
            response.getWriter().println(username + " has successfully logged in!");
        }
    }
}
