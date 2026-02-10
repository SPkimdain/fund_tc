package testcase.rule.quality.DatabaseConnectionRaceConditionChecker

import java.sql.Connection
import java.sql.DriverManager

val top_conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydb")                     // @violation

class TestCase {
    val inst_conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydb")                // good

    object Nested {
        val obj_conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydb")             // @violation

        class DoubleNested {
            val nest_inst_conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydb")   // good
        }
    }

    companion object {
        val companion_conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydb")       // @violation
    }
}