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
public class ElTest4 {

    Connection con;

    public ElTest4() throws SQLException {
        con = DriverManager.getConnection("jdbc:oracle:thin:@1.1.1.1:1521:ora9", "john", "1111"); /* BUG */
    }

    /*
    test for el intra
    el pattern : a.b
     */
    public void test4Driver(HttpServletRequest request) throws SQLException {
        Map map = new HashMap();
        String name = request.getParameter("name");

        User user = new User(name, null);

        user.setName(name);

        map.put("user", user);

        String nameFromMap = (String)com.fasoo.jspconv.util.ElEvaluator.evaluate(map, "${user.name}");

        PreparedStatement pstmt = null;
        try {
            String query = nameFromMap;
            pstmt = con.prepareStatement(query); /* BUG */
        } finally {
            if (pstmt != null) try { pstmt.close(); } catch (Exception e) {}
        }
    }
}
