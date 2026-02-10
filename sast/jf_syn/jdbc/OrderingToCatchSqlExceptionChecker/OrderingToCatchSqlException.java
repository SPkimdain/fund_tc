import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

/**
 * Test case for rule, 'ORDERING_TO_CATCH_SQLEXCEPTION' JavaFinch checker
 * Same as resort rule 'Ordering to catch SQLException'
 * Test case 설명, 디비에 대한 자원(Statement) 사용시, catch구문에서 SQLException 처리(선언)가 필요하다.
 * 이때 SQLException 처리(선언) 뿐만 아니라 Exception 처리(선언)도 함께 기술해야 한다.
 * 왜냐하면, 추가적인 Exception들이 발생할 수 있기 때문이다.
 */
public class OrderingToCatchSqlException {

    public void test() {
        // 선언부
        Connection conn = null;
        try {
            conn = DriverManager.getConnection("host","id","password");
            // do something.
        } catch (SQLException sqle) { // @violation
            if (conn != null) {
                try {
                    conn.rollback();
                } catch (SQLException e) {
                }
            }
            // 로그 기록 및 관련 사항 처리
        } finally {
            // 자원 해제 관련 코드 생략(rs, stmt and conn, etc)
        }
    }

    // Good
    public void safe() {
        // 선언부
        Connection conn = null;
        try {
            conn = DriverManager.getConnection("host","id","password");
            // do something.
        } catch (SQLException sqle) {
            if (conn != null) {
                try {
                    conn.rollback();
                } catch (SQLException e) {
                }
            }
            // 로그 기록 및 관련 사항 처리
        } catch (Exception e) {

        } finally {
            // 자원 해제 관련 코드 생략(rs, stmt and conn, etc)
        }
    }
}
