package cert.dcl;

import java.sql.DriverManager;
import javax.servlet.http.HttpServlet;

public class DirectManagementOfConnections extends HttpServlet {
    private Connection conn;
    public void dbConnection(String url, String user, String pw) {
        try {
            conn = DriverManager.getConnection(url, user, pw);  // @violation
        } catch (SQLException e) {
            System.err.println("...");
        } finally {
            //...
        }
    }
}