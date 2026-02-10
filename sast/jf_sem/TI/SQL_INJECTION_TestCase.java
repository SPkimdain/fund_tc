package ti;

import javax.servlet.http.*;

import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.ResultSet;
import java.sql.DriverManager;

import java.net.URLEncoder;

/*
    SQL_INJECTION checker 를 검증하기 위한 test case
 */
/* OPT : -show_followers */
public class SQL_INJECTION_TestCase extends HttpServlet {
    private Connection conn;
    private Statement stmt;
    private ResultSet rs;
    @SuppressWarnings("unchecked")
    public SQL_INJECTION_TestCase(String password) {
        super();
        Connection con = null;
        try {
            // 1. Driver를 로딩한다.
            Class.forName("oracle.jdbc.driver.OracleDriver");
            // 2. Connection 얻어오기
            con = DriverManager.getConnection("jdbc:oracle:thin:@아이피주소:1521:ora9", "john", password);
            // 3. Statement 얻기 --> 쿼리문 작성하여 적용하기 위한 용도
            stmt = con.createStatement();
        } catch (ClassNotFoundException e) {} catch (SQLException e) {}
        finally {
            if (con != null) {
                try {
                    con.close();
                } catch (SQLException e) {
                }
            }
        }
    }
    @SuppressWarnings("unchecked")
    public void doPost(HttpServletRequest req, HttpServletResponse res) {
        try {
            String name = req.getParameter("name"); // tainted input has come
            String query = "select * from account where name = '" + name + "'";
            doTransaction(query); /* BUG */

            conn.prepareStatement(query); /* BUG */
            stmt.execute(query); /* BUG */
            stmt.executeQuery(query); /* BUG */
            stmt.executeUpdate(query); /* BUG */
        } catch (Exception e) {
            System.out.println("Exception");
        }
    } /* BUG 2 */ //RESOURCE LEAK, RESOURCE_LEAK
    private void doTransaction(String query) throws SQLException {
        stmt.execute(query);
    }
    @SuppressWarnings("unchecked")
    public void doPost2(HttpServletRequest req, HttpServletResponse res) {
        try {
            String name = req.getQueryString(); // tainted input has come
            String query = "select * from account where name = '" + name + "'";
            doTransaction(query); /* BUG */

            conn.prepareStatement(query); /* BUG */
            stmt.execute(query); /* BUG */
            stmt.executeQuery(query); /* BUG */
            stmt.executeUpdate(query); /* BUG */
        } catch (Exception e) {
            System.out.println("Exception");
        }
    } /* BUG 2 */ //RESOURCE LEAK, RESOURCE_LEAK
    @SuppressWarnings("unchecked")
    public void doPost3(HttpServletRequest req, HttpServletResponse res) {
        try {
            String name = req.getQueryString(); // tainted input has come
            String query = "select * from account where name = '" + name + "'";
            query = URLEncoder.encode(query);
            doTransaction(query); /* BUG */

            conn.prepareStatement(query); /* SAFE */
            stmt.execute(query); /* SAFE */
            stmt.executeQuery(query); /* SAFE */
            stmt.executeUpdate(query); /* SAFE */
        } catch (Exception e) {
            System.out.println("Exception");
        }
    } /* BUG 2 */ //RESOURCE LEAK, RESOURCE_LEAK
}
