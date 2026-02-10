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
public class ElTest12 {

    Connection con;

    public ElTest12() throws SQLException {
        con = DriverManager.getConnection("jdbc:oracle:thin:@1.1.1.1:1521:ora9", "john", "1111"); /* BUG */
    }

    /*
    test for el simple inter
    source is inter, sink is inter
    el pattern : a.b
     */
    public void test12Driver(HttpServletRequest request) throws SQLException {
        Map map = new HashMap();

        test12Source(map, request);

        test12Sink(map); /* BUG */
        test12SinkSafe(map); /* SAFE */
        test12SinkMaybe(map); /* BUG */
    }

    public void test12Source(Map map, HttpServletRequest request) {
        String name = request.getParameter("user");

        User user = new User(null, null);
        user.name = name;

        map.put("user", user);
    }

    public void test12Sink(Map map) throws SQLException {
        String nameFromMap = (String)com.fasoo.jspconv.util.ElEvaluator.evaluate(map, "${true?user.name:\"abcd\"}");

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

    public void test12SinkSafe(Map map) throws SQLException {
        String nameFromMap = (String)com.fasoo.jspconv.util.ElEvaluator.evaluate(map, "${false?user.name:\"abcd\"}");

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

    public void test12SinkMaybe(Map map) throws SQLException {
        String nameFromMap = (String)com.fasoo.jspconv.util.ElEvaluator.evaluate(map, "${user.name?user.name:\"abcd\"}");

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
