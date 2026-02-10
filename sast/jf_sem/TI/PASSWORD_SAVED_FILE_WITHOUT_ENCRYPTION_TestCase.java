package ti;

import javax.crypto.Cipher;
import javax.crypto.NoSuchPaddingException;
import javax.servlet.http.HttpServletRequest;
import java.io.*;
import java.net.Socket;
import java.net.UnknownHostException;
import java.security.NoSuchAlgorithmException;
import java.sql.*;

/**
 * Writer: Gyuhang Shim
 * Date: 9/18/12
 */
/* OPT : -show_followers */
public class PASSWORD_SAVED_FILE_WITHOUT_ENCRYPTION_TestCase {
    public void test () {
        Socket socket = null;
        PrintWriter out = null;
        try {
            socket = new Socket("taranis", 4444); // TAINTED
            out = new PrintWriter(socket.getOutputStream(), true);
            String password = getPassword();
            out.write(password);  // if getPassword() method is registered as sink method, this is bug.
        } catch (FileNotFoundException e) {
        } catch (UnknownHostException e) {
        } catch (IOException e) {
        }  finally {
            if (out != null) out.close();
            if (socket != null) {
                try {
                    socket.close();
                } catch (IOException e) {
                }
            }
        }
    }

    public void test2 (HttpServletRequest request) {
        String userName = request.getParameter("username");
        String password = request.getParameter("password");

        PreparedStatement p = null;

        try {
            // ...
            if (userName == null || password == null || !isAuthenticatedUser(userName,password)) {
                throw new Exception("인증에러");
            }
            p = conn.prepareStatement("INSERT INTO employees VALUES(?,?)");
            p.setString(1, userName);  /* NOT_BUG */
            p.setString(2, password);  /* NOT_BUG */
            p.execute();
        } catch (SQLException e) {
        } catch (Exception e) {
        }
        finally {
            if (p != null) {
                try {
                    p.close();
                } catch (Exception e) {}
            }
            if (conn != null) {
                try {
                    conn.close();
                } catch (SQLException e) {
                }
            }
        }
    }

    public void test3 (HttpServletRequest request, String url, String name) {
        FileInputStream in = null;
        Connection con = null;
        Connection taintedCon = null;
        try {
            String taintedPasswd = request.getParameter("passwd"); // TAINTED
            in = new FileInputStream("file");
            byte [] pass = new byte[8];
            in.read(pass); // TAINTED

            con = DriverManager.getConnection(url, name, new String(pass)); /* BUG 2 */
            taintedCon = DriverManager.getConnection(url, name, taintedPasswd); /* BUG 1 */
        } catch (FileNotFoundException e) {
        } catch (SQLException e) {
        } catch (IOException e) {
        } finally {
            if (taintedCon != null) {
                try {
                    taintedCon.close();
                } catch (SQLException e) {
                }
            }
            if (con != null) {
                try {
                    con.close();
                } catch (SQLException e) {
                }
            }
            try {
                if(in != null) in.close();
            } catch (IOException e) {}
        }
    }

    public void test4 (String url, String name) {
        DataInputStream dis = null;
        Connection con = null;
        Connection con2 = null;
        try {
            dis = new DataInputStream(new FileInputStream("tainted.file"));
            byte [] pass = new byte[8];
            dis.read(pass);
            con = DriverManager.getConnection(url, name, new String(pass)); /* BUG 2 */

            String pass2 = new String(pass); /* BUG */
            con2 = DriverManager.getConnection(url, name, pass2); /* BUG */
        } catch (FileNotFoundException e) {
        } catch (IOException e) {
        } catch (SQLException e) {
        } finally {
            if (con2 != null) {
                try {
                    con2.close();
                } catch (SQLException e) {
                }
            }
            if (con != null) {
                try {
                    con.close();
                } catch (SQLException e) {
                }
            }
            try {
                if(dis != null) dis.close();
            } catch (IOException e) {}
        }
    }
    public void test5(String url, String name) {
        BufferedInputStream bis = null;
        try {
            bis = new BufferedInputStream(new FileInputStream("tainted.file"));

            byte [] pass = new byte[8];
            bis.read(pass);
            conn = DriverManager.getConnection(url, name, new String(pass)); /* BUG 2 */

        } catch (FileNotFoundException e) {
        } catch (SQLException e) {
        } catch (IOException e) {
        } finally {
            if (conn != null) {
                try {
                    conn.close();
                } catch (SQLException e) {
                }
            }
            try {
                if(bis != null) bis.close();
            } catch (IOException e) {}
        }
    }

    public void test6(String url, String name) {
        BufferedInputStream bis = null;
        try {
            bis = new BufferedInputStream(new FileInputStream("tainted.file"));

            byte [] pass = new byte[8];
            bis.read(pass, 10, 10);
            conn = DriverManager.getConnection(url, name, new String(pass)); /* BUG 2 */

        } catch (FileNotFoundException e) {
        } catch (SQLException e) {
        } catch (IOException e) {
        } finally {
            if (conn != null) {
                try {
                    conn.close();
                } catch (SQLException e) {
                }
            }
            try {
                if(bis != null) bis.close();
            } catch (IOException e) {}
        }
    }
    public void test7(Reader reader, String url, String name) throws IOException, SQLException {
        BufferedReader br = null;
        Connection con = null;
        try {
            br = new BufferedReader(reader);
            char [] pass = new char[8];
            br.read(pass, 8, 8);
            con = DriverManager.getConnection(url, name, new String(pass)); /* BUG 1 */
        } catch (Exception e) {

        } finally {
            if (con != null) {
                con.close();
            }
            if (br != null) {
                br.close();
            }
        }
    }
    public void safeTest() {
        Socket socket = null;
        PrintWriter out = null;
        try {
            socket = new Socket("taranis", 4444); // TAINTED
            out = new PrintWriter(socket.getOutputStream(), true);
            String password = getPassword();
            Cipher c = Cipher.getInstance("AES/CBC/PKCS5Padding");

            String encryptedPassword = new String(c.update(password.getBytes()), 0, 10);
            out.write(encryptedPassword, 0, encryptedPassword.length()); /* SAFE */
        } catch (FileNotFoundException e) {
        } catch (UnknownHostException e) {
        } catch (IOException e) {
        } catch (NoSuchAlgorithmException e) {
        } catch (NoSuchPaddingException e) {
        } finally {
            if (out != null) out.close();
            if (socket != null) {
                try {
                    socket.close();
                } catch (IOException e) {
                }
            }
        }
    }
    private boolean isAuthenticatedUser(String userName, String password) {
        return true;
    }
    public String getPassword() {return "1234";}
    private Connection conn;
    private Statement stmt;
    private ResultSet rs;

    @SuppressWarnings("unchecked")
    public PASSWORD_SAVED_FILE_WITHOUT_ENCRYPTION_TestCase(String password) {
        super();
        try {
            // 1. Driver를 로딩한다.
            Class.forName("oracle.jdbc.driver.OracleDriver");
            // 2. Connection 얻어오기
            conn = DriverManager.getConnection("jdbc:oracle:thin:@아이피주소:1521:ora9", "john", password);
            // 3. Statement 얻기 --> 쿼리문 작성하여 적용하기 위한 용도
            stmt = conn.createStatement();
        } catch (ClassNotFoundException e) {} catch (SQLException e) {}
        finally {
            if (conn != null) {
                try {
                    conn.close();
                } catch (SQLException e) {
                }
            }
        }
    }
}
