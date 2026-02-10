package el;

import java.lang.Exception;
import java.lang.String;
import java.util.HashMap;
import java.util.Map;

import javax.servlet.http.*;

import java.sql.Connection;
import java.sql.SQLException;
import java.sql.PreparedStatement;
import java.sql.DriverManager;


/* OPT : -analyze_spring -show_followers */
public class ElTest2 {

    Connection con;

    public ElTest2() throws SQLException {
        con = DriverManager.getConnection("jdbc:oracle:thin:@1.1.1.1:1521:ora9", "john", "1111"); /* BUG */
    }

    /*
    test for simple inter procedural analysis
    taint info is passed from callee to caller via map object passed as parameter
     */
    public void test2(Map map, HttpServletRequest req) {
        String taint = (String)req.getParameter("taint");

        map.put("taint", taint);
    }

    public void test2Driver(HttpServletRequest req) throws SQLException {
        Map map = new HashMap();

        test2(map, req);

        String s = (String)map.get("taint");

        PreparedStatement pstmt = null;
        try {
            String query = "select * from account where name = '" + s + "'";
            pstmt = con.prepareStatement(query); /* BUG */
        } finally {
            if (pstmt != null) try { pstmt.close(); } catch (Exception e) {}
        }
    }
}
