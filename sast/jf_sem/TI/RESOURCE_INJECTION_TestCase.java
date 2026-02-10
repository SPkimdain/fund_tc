package ti;

import java.io.FileInputStream;
import java.io.IOException;
import java.net.HttpURLConnection;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Properties;
import javax.servlet.http.HttpServletRequest;

/**
 * Writer: Gyuhang Shim
 * Date: 5/3/12
 */
/* OPT : -show_followers */
public class RESOURCE_INJECTION_TestCase {
    public void test(HttpServletRequest request, HttpURLConnection connection) throws IOException {
        int def = 1000;
        ServerSocket serverSocket;
        Properties props = new Properties();
        String fileName = "file_list";
        FileInputStream in = new FileInputStream(fileName);
        props.load(in); /* BUG */ // Resource Leak
        in.close();

        // 외부에서 입력한 데이터를 받는다.
        String service = request.getParameter("service_no");//String service = props.getProperty("Service No"); // tainted
        int port = Integer.parseInt(service); // tainted service aliased

        // 외부에서 입력받은 값으로 소켓을 생성한다.
        if (port != 0) {
            serverSocket = new ServerSocket(port + 3000); /* BUG 2 */ // RESOURCE_INJECTION, INTEGER_OVERFLOW
        } else {
            serverSocket = new ServerSocket(def + 3000);
        }
        Socket socket = new Socket("abc", port); /* BUG */
        socket.close();
    }

    public void test2(HttpServletRequest request, Properties props, HttpURLConnection connection) throws IOException {
        // 외부에서 입력한 데이터를 받는다.
        String service = request.getParameter("servlet_no");//String service = props.getProperty("Service No"); // tainted

        // if 문 안에 없는 indexOf("&") 호출 이므로 filter되지 않았다고 간주
        service.indexOf("&"); /* BUG */ //NULL_RETURN_STD
        int port = Integer.parseInt(service); // safe service aliased
        ServerSocket serverSocket = new ServerSocket(port + 3000); /* BUG 2 */ //RESOURCE_INJECTION, INTEGER_OVERFLOW
        serverSocket.close();
    }

    public void test3(HttpServletRequest request, Properties props, HttpURLConnection connection) throws IOException {
        // 외부에서 입력한 데이터를 받는다.
        String service = request.getParameter("servlet_no");//String service = props.getProperty("Service No"); // tainted

        // indexOf 의 parameter ("&&") 가 filter method 에 등록되지 않은 경우
        if (service.indexOf("&&") != -1) { /* BUG */ //NULL_RETURN_STD // "service" is filtered by "indexOf" method of J_FilterIO in "if" condition. Assumed safe
            int port = Integer.parseInt(service); // safe service aliased
            ServerSocket serverSocket = new ServerSocket(port + 3000); /* BUG 2 */
            serverSocket.close();
        }
    }

    public void test4(HttpServletRequest request, Properties props, HttpURLConnection connection) throws IOException {
        // 외부에서 입력한 데이터를 받는다.
        String service = request.getParameter("servlet_no");//String service = props.getProperty("Service No"); // tainted

        // indexOf 의 parameter ("\r") 가 filter method 에 등록되지 않은 경우
        if (service.indexOf("\r") != -1) { /* BUG */ //NULL_RETURN_STD // "service" is filtered by "indexOf" method of J_FilterIO in "if" condition. Assumed safe
            int port = Integer.parseInt(service); // safe service aliased
            ServerSocket serverSocket = new ServerSocket(port + 3000); /* BUG 2 */ //RESOURCE_INJECTION, INTEGER_OVERFLOW
            serverSocket.close();
        }
    }

    public void safeTest1(HttpServletRequest request, Properties props, HttpURLConnection connection) throws IOException {
        // 외부에서 입력한 데이터를 받는다.
        String service = request.getParameter("servlet_no");//String service = props.getProperty("Service No"); // tainted

        // indexOf 의 반환값이 -1 과 동등 연산자에 의해서 비교 될 경우
        if (service.indexOf("&") != -1) { /* BUG */ //NULL_RETURN_STD // "service" is filtered by "indexOf" method of J_FilterIO in "if" condition. Assumed safe
            int port = Integer.parseInt(service); // safe service aliased
            ServerSocket serverSocket = new ServerSocket(port); /* SAFE */
            serverSocket.close();
        }
    }
    public void safeTest2(HttpServletRequest request, Properties props, HttpURLConnection connection) throws IOException {
        // 외부에서 입력한 데이터를 받는다.
        String service = request.getParameter("servlet_no");//String service = props.getProperty("Service No"); // tainted

        // indexOf("<") 에 의해서 filter 되는 경우
        if (service.indexOf("<") != -1) { /* BUG */ //NULL_RETURN_STD // "service" is filtered by "indexOf" method of J_FilterIO in "if" condition. Assumed safe
            int port = Integer.parseInt(service); // safe service aliased
            ServerSocket serverSocket = new ServerSocket(port); /* SAFE */
            serverSocket.close();
        }
    }
    public void safeTest3(HttpServletRequest request, Properties props, HttpURLConnection connection) throws IOException {
        // 외부에서 입력한 데이터를 받는다.
        String service = request.getParameter("servlet_no");//String service = props.getProperty("Service No"); // tainted

        // indexOf(">") 에 의해서 filter 되는 경우
        if (service.indexOf(">") != -1) { /* BUG */ //NULL_RETURN_STD // "service" is filtered by "indexOf" method of J_FilterIO in "if" condition. Assumed safe
            int port = Integer.parseInt(service); // safe service aliased
            ServerSocket serverSocket = new ServerSocket(port); /* SAFE */
            serverSocket.close();
        }
    }

    public void safeTest4(HttpServletRequest request, Properties props, HttpURLConnection connection) throws IOException {
        // 외부에서 입력한 데이터를 받는다.
        String service = request.getParameter("servlet_no");//String service = props.getProperty("Service No"); // tainted

        // indexOf 의 반환값이 >= 에 의해서 비교 될 경우
        if (service.indexOf("&") >= -1) { /* BUG */ //NULL_RETURN_STD // "service" is filtered by "indexOf" method of J_FilterIO in "if" condition. Assumed safe
            int port = Integer.parseInt(service); // safe service aliased
            ServerSocket serverSocket = new ServerSocket(port); /* SAFE */
            serverSocket.close();
        }
    }

    public void safeTest5(HttpServletRequest request, Properties props, HttpURLConnection connection) throws IOException {
        // 외부에서 입력한 데이터를 받는다.
        String service = request.getParameter("servlet_no");//String service = props.getProperty("Service No"); // tainted

        // service 가 if 문 안에서 filter 되고, if 문의 밖에서 사용 될 경우 재대로 filter 됬는지 검사
        if (service.indexOf("&") != -1) { /* BUG */ //NULL_RETURN_STD // "service" is filtered by "indexOf" method of J_FilterIO in "if" condition. Assumed safe
            System.out.println("test");
        }
        int port = Integer.parseInt(service); // safe service aliased
        ServerSocket serverSocket = new ServerSocket(port); /* SAFE */
        serverSocket.close();
    }

    public void safeTest6(HttpServletRequest request, Properties props, HttpURLConnection connection) throws IOException {
        // 외부에서 입력한 데이터를 받는다.
        String service = request.getParameter("servlet_no");//String service = props.getProperty("Service No"); // tainted

        // if 문의 다른 형식으로 indexOf 에 의해서 service 가 filter 된 경우
        boolean b = service.indexOf("&") != -1; /* BUG */ //NULL_RETURN_STD // is equivalent to b = if(service.indexOf("..") != -1) 1 else 0 after compilation
        if(b) System.out.println("test");

        int port = Integer.parseInt(service); // safe service aliased
        ServerSocket serverSocket = new ServerSocket(port); /* SAFE */
        serverSocket.close();
    }
}
