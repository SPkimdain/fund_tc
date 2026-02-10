package security;

import javax.crypto.Cipher;

import java.lang.String;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Properties;

public class HardCodedUserNameAndPassword {

    String gTiger;

    public Connection DBConn(Connection conn, String url, String id, String passwd) {
        try {
            String tiger = "tiger";
            conn = DriverManager.getConnection(url, id, "tiger"); // @violation
            conn = DriverManager.getConnection(url, id, tiger); // @violation
            conn = DriverManager.getConnection(url, id, passwd); /* SAFE */
        } catch (SQLException e) {}
        return conn;
    }

    public Connection DBConn2(Properties props, Cipher cipher, Connection conn, String url, String id) {
        try {
            String password = props.getProperty("passwd");
            byte [] decrypted_pwd = cipher.doFinal(password.getBytes());
            password = new String(decrypted_pwd);
            conn = DriverManager.getConnection(url, id, password); /* SAFE */
        } catch (SQLException e) {}
        return conn;
    }

    public Connection DBConn3(Connection conn, String url, Properties properties) {
        try {
            properties.put("passwd", "tiger");
            conn = DriverManager.getConnection(url, properties); // @violation
        } catch (SQLException e) {}
        return conn;
    }

    public Connection DBConn4(Connection conn, String url, Properties properties, String passwd) {
        try {
            properties.put("passwd", passwd);
            conn = DriverManager.getConnection(url, properties); /* SAFE */
        } catch (SQLException e) {}
        return conn;
    }

    public Connection DBConn5(Connection conn, String url, Properties properties) {
        try {
            properties.put("dummy", "tiger");
            conn = DriverManager.getConnection(url, properties); /* SAFE */
        } catch (SQLException e) {}
        return conn;
    }

    public Connection DBConn6(Connection conn, String url, String id, String passwd) {
        try {
            conn = DriverManager.getConnection(url, id, gTiger); // @violation
        } catch (SQLException e) {}
        return conn;
    }

    static {
        gTiger = "gTiger";
    }

    public void KUM() {
        Intent actIntent2 = new Intent(Intent.ACTION_MAIN);
        actIntent2.putExtra("id", "abcd");
        actIntent2.putExtra("pass", "abcdabcd");
        actIntent2.putExtra("id", "password");
    }
}
