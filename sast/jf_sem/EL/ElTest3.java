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
public class ElTest3 {

    Connection con;

    public ElTest3() throws SQLException {
        con = DriverManager.getConnection("jdbc:oracle:thin:@1.1.1.1:1521:ora9", "john", "1111"); /* BUG */
    }

    public void test3Source(Map map, HttpServletRequest req) {
        String taint = (String)req.getParameter("taint");

        map.put("taint", taint);
    }

    public void test3Sink(Map map) throws SQLException {
        String s = (String)map.get("taint");

        PreparedStatement pstmt = null;
        try {
            String query = s;
            //TODO
            //String query = "select * from account where name = '" + s + "'";
            pstmt = con.prepareStatement(query);
        } finally {
            if (pstmt != null) try { pstmt.close(); } catch (Exception e) {}
        }
    }

    /*
    test for interprocedural analysis
    both sink and source are interprocerual
     */
    public void test3Driver(HttpServletRequest req) throws SQLException {
        Map map = new HashMap();

        test3Source(map, req);

        test3Sink(map); /* BUG */
    }

}
