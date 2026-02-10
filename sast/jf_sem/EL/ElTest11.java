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
public class ElTest11 {

    Connection con;

    public ElTest11() throws SQLException {
        con = DriverManager.getConnection("jdbc:oracle:thin:@1.1.1.1:1521:ora9", "john", "1111"); /* BUG */
    }

    /*
    test for el simple inter
    source is inter, sink is inter
    el pattern : a.b
     */
    public void test11Driver(HttpServletRequest request) throws SQLException {
        Map map = new HashMap();

        test11Source(map, request);

        test11Sink(map); /* SAFE */
    }

    public void test11Source(Map map, HttpServletRequest request) {
        String name = request.getParameter("user");

        User user = new User(null, null);
        user.name = name;

        map.put("user", user);
    }

    public void test11Sink(Map map) throws SQLException {
        String nameFromMap = (String)com.fasoo.jspconv.util.ElEvaluator.evaluate(map, "${\'${\'}user.name}");
        String nameFromMap2 = (String)com.fasoo.jspconv.util.ElEvaluator.evaluate(map, "\\${user.name}");

        PreparedStatement pstmt = null;
        PreparedStatement pstmt2 = null;
        try {
            String query = nameFromMap;
            String query2 = nameFromMap2;
            //TODO
            //String query = "select * from account where name = '" + s + "'";
            pstmt = con.prepareStatement(query);
            pstmt2 = con.prepareStatement(query2);
        } finally {
            if (pstmt != null) try { pstmt.close(); } catch (Exception e) {}
            if (pstmt2 != null) try { pstmt2.close(); } catch (Exception e) {}
        }
    }

}
