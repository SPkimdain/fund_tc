package scaffold.nd.throw_exception;

import java.sql.Connection;
import java.sql.SQLException;

public class ExceptionTest {
	private Connection con;
	private boolean isUseConn;

	public Connection getConnection() throws SQLException {
		ex.test(con ==  null, (short)1); // throw SQLException if con is null
		if (isUseConn) {
			isUseConn = false;
			con.close(); /* NOT BUG */
			isUseConn = true;
			return con;
		}
		return null;
	}

	public Connection getConnection2() throws SQLException {
		ex.test(con !=  null, (short)1); // throw SQLException if con is null
		if (isUseConn) {
			isUseConn = false;
			con.close(); /* BUG */
			isUseConn = true;
			return con;
		}
		return null;
	}
}
