import java.io.*;

public class SecurityCallThrowsFinally {
    public static void doOperation(String some_file) {
        // ... code to check or set character encoding ...
        try {
            BufferedReader reader =
                    new BufferedReader(new FileReader(some_file));
            Statement stmt = new Statement();
            PreparedStatement pStmt = new PreparedStatement();
            Connection conn = new Connection();
            try {
                // Do operations
            } finally {
                reader.close();                         // @violation
            }

            try {
                // Do operations
            } finally {
                try {
                    reader.close();                         /* Safe */
                    // Do operations
                } catch (IOException x) {
                    // ... Other cleanup code ...
                }
            }
        } catch (IOException x) {
            // Forward to handler
        } finally {
            try {

                if(stmt != null) stmt.close();
                if(pStmt != null) pStmt.close();
                if(conn != null) conn.close();  // @violation

            } catch (SQLException e) {

            } catch (SQLFeatureNotSupportedException e) {

            } finally {

            }
        }
    }
}

class BufferedReader {
    public BufferedReader(FileReader reader) {}

    public void close() throws IOException {
        // ...
    }
}

class Statement {
    public Statement() {}

    public void close() throws SQLException {
        // ...
    }
}

class PreparedStatement {
    public PreparedStatement() {}

    public void close() throws SQLFeatureNotSupportedException {
        // ...
    }
}

class Connection {
    public Connection() {}

    public void close() throws SecurityException {
        // ...
    }
}