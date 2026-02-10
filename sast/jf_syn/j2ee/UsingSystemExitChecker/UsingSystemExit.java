import javax.servlet.http.HttpServlet;

public class InterceptExit extends HttpServlet {

    public void doPost() {
        System.exit(1);             // @violation
        System.out.println("This never executes");
    }

    public void doGet() {
        System.exit(1);             // @violation
        System.out.println("This never executes");
    }

    public void service() {
        System.exit(1);             // @violation
        System.out.println("This never executes");
    }
}