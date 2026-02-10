import javax.servlet.http.HttpServlet;

public class InterceptExit extends HttpServlet {

    public void doPost() {
        Foo foo = new Foo();
        new Thread(foo).run();      // @violation
    }

    public void doGet() {
        Foo foo = new Foo();
        new Thread(foo).run();      // @violation
    }

    public void service() {
        Foo foo = new Foo();
        new Thread(foo).run();      // @violation
    }
}