package el;

import java.lang.Exception;
import java.lang.String;
import java.util.HashMap;
import java.util.Map;

import javax.servlet.http.*;

import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.DriverManager;


/* OPT : -analyze_spring -show_followers */
public class ElTest5 {

    Connection con;

    public ElTest5() throws SQLException {
        con = DriverManager.getConnection("jdbc:oracle:thin:@1.1.1.1:1521:ora9", "john", "1111"); /* BUG */
    }

    /*
    test for el simple inter
    source is intra, sink is inter
    el pattern : a
     */
    public void test5Driver(HttpServletRequest request) throws SQLException {
        Map map = new HashMap();
        String name = request.getParameter("name");

        map.put("user", name);

        test5Sink(map); /* BUG */
    }

    public void test5Sink(Map map) throws SQLException {
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
