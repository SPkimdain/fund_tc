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
public class ElTest9 {

    Connection con;

    public ElTest9() throws SQLException {
        con = DriverManager.getConnection("jdbc:oracle:thin:@1.1.1.1:1521:ora9", "john", "1111"); /* BUG */
    }

    /*
    test for el simple inter
    source is inter, sink is intra
    el pattern : a.b
     */
    public void test9Driver(HttpServletRequest request) throws SQLException {
        Map map = new HashMap();

        test9Source(map, request);

        String nameFromMap = (String)com.fasoo.jspconv.util.ElEvaluator.evaluate(map, "${user[\"name\"]}");

        PreparedStatement pstmt = null;
        try {
            String query = nameFromMap;
            //TODO
            //String query = "select * from account where name = '" + s + "'";
            pstmt = con.prepareStatement(query); /* BUG */
        } finally {
            if (pstmt != null) try { pstmt.close(); } catch (Exception e) {}
        }

    }

    public void test9Source(Map map, HttpServletRequest request) {
        String name = request.getParameter("user");

        User user = new User(null, null);
        user.name = name;

        map.put("user", user);
    }
}
