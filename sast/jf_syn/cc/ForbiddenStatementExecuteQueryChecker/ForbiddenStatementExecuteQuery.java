import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

public class ForbiddenStatementExecuteQuery {
    public class ExecuteQueryBad1 {
        void func(Table table, Id id) {
            String s = ";";
            try {
                Connection connection = DriverManager.getConnection(s,"name","pass");
                Statement statement = connection.createStatement();
                statement.executeQuery("SELECT * FROM" + table + "where ID =" + id);        // @violation
            } catch(Exception e) {
                /* do something */
            }
        }
    }
}