package rl;

import java.lang.String;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

/**
 * Created with IntelliJ IDEA.
 * User: starblood
 * Date: 12. 11. 24.
 * Time: 오후 12:55
 */
public class DriverManagerTest {
    public void test (String password) {
        Connection conn = null;

        try {
            conn = DriverManager.getConnection("host", "id", password);
        } catch (SQLException e) {
        }
    } /* BUG */ // Resource Leak

    public void test_safe (String password) {
        Connection conn = null;

        try {
            conn = DriverManager.getConnection("host", "id", password);
        } catch (SQLException e) {
        } finally {
            if (conn != null) {
                try {
                    conn.close(); // resource released
                } catch (Exception e) {
                }
            }
        }
    } /* SAFE */
}
