package scaffold.nd.throw_exception;

import java.sql.SQLException;

public class ex {
    public static final String CONST = "abcd";
    public static final void test(boolean cond, short state) throws SQLException {
        if (cond) throw new SQLException();
    }
}
