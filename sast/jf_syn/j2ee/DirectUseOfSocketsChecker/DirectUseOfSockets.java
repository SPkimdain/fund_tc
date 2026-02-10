import java.net.Socket;
import javax.servlet.http.HttpServlet;

public class DirectUseOfSockets extends HttpServlet {

    private Socket socket;
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException {
        try {
            // J2EE 어플리케이션에서 프레임워크 메소드 호출 대신에 소켓(Socket)을 직접 사용하고 있다.
            socket = new Socket("kisa.or.kr", 8080); // @violation
        } catch (UnknownHostException e) {
            System.err.println("UnknownHostException occurred");
        } catch (IOException e) {
            System.err.println("IOException occurred");
        } finally {
            //...
        }
    }
}