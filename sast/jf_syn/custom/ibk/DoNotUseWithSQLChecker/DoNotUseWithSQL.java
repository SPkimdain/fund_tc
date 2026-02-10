package jdbc;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

public class DBConnection {
    private Connection conn;
    private Statement stmt;
    private PreparedStatement  pstm;

    public DBConnection() {
        try {
            String url = "jdbc:mysql://localhost/?characterEncoding=UTF-8&serverTimezone=UTC";
            String user = "root";
            String passwd = "1234";

            conn = DriverManager.getConnection(url, user, passwd);
            stmt = conn.createStatement();

            // executeUpdate method
            String query1 = "INSERT INTO emp20\n" +
                    "        SELECT * FROM (\n" +
                    "            WITH dept20 AS (\n" +
                    "                SELECT empno, ename FROM emp WHERE deptno = 20\n" +
                    "            )\n" +
                    "            SELECT * FROM dept20\n" +
                    "        )";
            stmt.executeUpdate(query1); // @violation
            stmt.executeUpdate("INSERT INTO emp20\n" + // @violation
                    "        SELECT * FROM (\n" +
                    "            WITH dept20 AS (\n" +
                    "                SELECT empno, ename FROM emp WHERE deptno = 20\n" +
                    "            )\n" +
                    "            SELECT * FROM dept20\n" +
                    "        )");
            stmt.executeUpdate("INSERT INTO emp20 SELECT * FROM ( WITH dept20 AS ( SELECT empno, ename FROM emp WHERE deptno = 20 ) SELECT * FROM dept20 )"); // @violation

            executeUpdate(stmt);

            // executeQuery method
            String query2 = "WITH RECURSIVE included_parts(sub_part, part) AS (\n" +
                    "            SELECT sub_part, part FROM parts WHERE part = 'our_product'\n" +
                    "            UNION ALL\n" +
                    "            SELECT p.sub_part, p.part\n" +
                    "            FROM included_parts pr, parts p\n" +
                    "            WHERE p.part = pr.sub_part\n" +
                    "        )\n" +
                    "        DELETE FROM parts\n" +
                    "        WHERE part IN (SELECT part FROM included_parts);";
            stmt.executeQuery(query2); // @violation
            stmt.executeQuery( // @violation
                    "WITH RECURSIVE included_parts(sub_part, part) AS (\n" +
                    "            SELECT sub_part, part FROM parts WHERE part = 'our_product'\n" +
                    "            UNION ALL\n" +
                    "            SELECT p.sub_part, p.part\n" +
                    "            FROM included_parts pr, parts p\n" +
                    "            WHERE p.part = pr.sub_part\n" +
                    "        )\n" +
                    "        DELETE FROM parts\n" +
                    "        WHERE part IN (SELECT part FROM included_parts);");
            stmt.executeQuery("WITH RECURSIVE included_parts(sub_part, part) AS ( SELECT sub_part, part FROM parts WHERE part = 'our_product' UNION ALL SELECT p.sub_part, p.part FROM included_parts pr, parts p WHERE p.part = pr.sub_part ) DELETE FROM parts WHERE part IN (SELECT part FROM included_parts);"); // @violation

//            String query22 = """
//                    WITH
//                        cte1 AS (SELECT a, b FROM table1),
//                        cte2 AS (SELECT c, d FROM table2)
//                    SELECT b, d FROM cte1 JOIN cte2
//                    WHERE cte1.a = cte2.c;
//                    """;
//            stmt.executeQuery(query22); // violation TODO: java 13

            // prepareStatement method
            String query3 = "INSERT INTO emp20\n" +
                    "        SELECT * FROM (\n" +
                    "            WITH dept20 AS (\n" +
                    "                SELECT empno, ename FROM emp WHERE deptno = ?\n" +
                    "            )\n" +
                    "            SELECT * FROM dept20\n" +
                    "        )";
            pstm = conn.prepareStatement(query3); // @violation
            pstm.setInteger(1, 20);
            pstm.executeUpdate();

            pstm = conn.prepareStatement("INSERT INTO emp20\n" + // @violation
                    "        SELECT * FROM (\n" +
                    "            WITH dept20 AS (\n" +
                    "                SELECT empno, ename FROM emp WHERE deptno = ?\n" +
                    "            )\n" +
                    "            SELECT * FROM dept20\n" +
                    "        )");
            pstm.setInteger(1, 20);
            pstm.executeUpdate();

            stmt.close();
            conn.close();

        } catch (SQLException e) {
            // do nothing
        }
    }

    private void executeUpdate(Statement stmt) {
        String query = "INSERT INTO emp20\n" +
                "        SELECT * FROM (\n" +
                "            WITH dept20 AS (\n" +
                "                SELECT empno, ename FROM emp WHERE deptno = 20\n" +
                "            )\n" +
                "            SELECT * FROM dept20\n" +
                "        )";
        stmt.executeUpdate(query); // @violation
        stmt.executeUpdate("INSERT INTO emp20\n" + // @violation
                "        SELECT * FROM (\n" +
                "            WITH dept20 AS (\n" +
                "                SELECT empno, ename FROM emp WHERE deptno = 20\n" +
                "            )\n" +
                "            SELECT * FROM dept20\n" +
                "        )");
        stmt.executeUpdate("INSERT INTO emp20 SELECT * FROM ( WITH dept20 AS ( SELECT empno, ename FROM emp WHERE deptno = 20 ) SELECT * FROM dept20 )"); // @violation
    }

    public static void main(String[] args) {
        new DBConnection();
    }

}