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
public class ElTest1 {

    Connection con;

    public ElTest1() throws SQLException {
        con = DriverManager.getConnection("jdbc:oracle:thin:@1.1.1.1:1521:ora9", "john", "1111"); /* BUG */
    }

    /*
    test for simple inter procedural analysis
    taint info is passed from caller to callee via map object passed as parmeter
     */
    public void test1(Map map) throws SQLException{
        String s = (String)com.fasoo.jspconv.util.ElEvaluator.evaluate(map, "${n}");

        PreparedStatement pstmt = null;
        try {
            pstmt = con.prepareStatement(s);
        } finally {
            if (pstmt != null) try { pstmt.close(); } catch (Exception e) {}
        }

    }

    /*
    test driver for test1 & simple intra
     */
    public void test1Driver(HttpServletRequest req) throws SQLException {
        Map map = new HashMap();
        map.put("n"   , req.getParameter("a"));
        test1(map); /* BUG */

        map.put("s", req.getParameter("s"));

        String s = (String)map.get("s");

        PreparedStatement pstmt = null;
        try {
            String query = "select * from account where name = '" + s + "'";
            pstmt = con.prepareStatement(query); /* BUG */
        } finally {
            if (pstmt != null) try { pstmt.close(); } catch (Exception e) {}
        }
    }
}
