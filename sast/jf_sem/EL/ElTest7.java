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
public class ElTest7 {

    Connection con;

    public ElTest7() throws SQLException {
        con = DriverManager.getConnection("jdbc:oracle:thin:@1.1.1.1:1521:ora9", "john", "1111"); /* BUG */
    }

    /*
    test for el simple inter
    source is inter, sink is inter
    el pattern : a
     */
    public void test7Driver(HttpServletRequest request) throws SQLException {
        Map map = new HashMap();

        test7Source(map, request);

        test7Sink(map); /* BUG */
    }

    public void test7Source(Map map, HttpServletRequest request) {
        String user = request.getParameter("user");
        map.put("user", user);
    }

    public void test7Sink(Map map) throws SQLException {
        String nameFromMap = (String)com.fasoo.jspconv.util.ElEvaluator.evaluate(map, "${user}");

        PreparedStatement pstmt = null;
        try {
            String query = nameFromMap;
            //TODO
            //String query = "select * from account where name = '" + s + "'";
            pstmt = con.prepareStatement(query);
        } finally {
            if (pstmt != null) try { pstmt.close(); } catch (Exception e) {}
        }
    }
}
