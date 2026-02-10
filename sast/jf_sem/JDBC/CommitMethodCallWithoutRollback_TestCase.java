package jdbc;

import java.lang.String;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

/**
 * Test case of checker for rule 'Using rollback when commit fails'.
 * User: starblood
 * Date: 12. 11. 26.
 * Time: 오전 9:15
 */
/* OPT : -show_followers */
public class CommitMethodCallWithoutRollback_TestCase {
    public void test1 (String password) {
        Connection conn = null;
        try {
            conn = DriverManager.getConnection("host","id",password);
            String sql = "SELECT name, age, address from ..";
            Statement stmt = conn.createStatement();
            // do something
            conn.commit();
        } catch (SQLException e) {
        } finally {
            if (conn != null) {
                try {
                    conn.close();
                } catch (SQLException e) {
                }
            }
        }
    } /* BUG 2 */

    public void test1_safe (String password) {
        Connection conn = null;
        try {
            conn = DriverManager.getConnection("host","id",password);
            String sql = "SELECT name, age, address from ..";
            Statement stmt = conn.createStatement();
            // do something
            conn.commit();
        } catch (SQLException e) {
            try {
                if (conn != null) {
                    conn.rollback();
                }
            } catch (SQLException e1) {
            }
        } finally {
            if (conn != null) {
                try {
                    conn.close();
                } catch (SQLException e) {
                }
            }
        }
    } /* BUG */ //resource leak

    public void startTransaction(Connection conn) throws SQLException {
        conn.commit();
    }
    public void test2 () {
        Connection conn = null;
        try {
            conn = DriverManager.getConnection("");
            startTransaction(conn);
        } catch (SQLException e) {
        } finally {
            if (conn != null) {
                try {
                    conn.close();
                } catch (SQLException e) {
                }
            }
        }
    } /* BUG */

    public void test2_safe () {
        Connection conn = null;
        try {
            conn = DriverManager.getConnection("");
            startTransaction(conn);
        } catch (SQLException e) {
            try {
                if (conn != null) {
                    conn.rollback();
                }
            } catch (SQLException e1) {
            }
        } finally {
            if (conn != null) {
                try {
                    conn.close();
                } catch (SQLException e) {
                }
            }
        }
    }

    public void test3() {
        Connection conn = null;
        try {
            conn = DriverManager.getConnection("");
            startTransaction(conn);
        } catch (SQLException e) {
            do_not_rollback(conn); // rollback
        } finally {
            if (conn != null) {
                try {
                    conn.close();
                } catch (SQLException e) {
                }
            }
        }
    } /* BUG */

    public void test3_safe () {
        Connection conn = null;
        try {
            conn = DriverManager.getConnection("");
            startTransaction(conn);
        } catch (SQLException e) {
            rollback(conn); // rollback
        } finally {
            if (conn != null) {
                try {
                    conn.close();
                } catch (SQLException e) {
                }
            }
        }
    }
    public void do_not_rollback(Connection conn) {

    }
    public void rollback(Connection conn) {
        try {
            if (conn != null) {
                conn.rollback();
            }
        } catch (SQLException e1) {
        }
    }
}
