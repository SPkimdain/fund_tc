package ti;

import javax.naming.InitialContext;
import javax.naming.NamingException;
import javax.sql.DataSource;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.sql.Connection;
import java.sql.SQLException;
import java.util.Properties;
import javax.servlet.http.HttpServletRequest;

/**
 * Writer: Gyuhang Shim
 * Date: 5/31/12
 */
public class EXTERNAL_CONTROL_OF_SYSTEM_OR_CONFIGURATION_SETTING_TestCase {
    public void foo() {
        FileInputStream in = null;
        try {
            InitialContext ctx = new InitialContext();
            DataSource dataSource = (DataSource)ctx.lookup("jdbc:ocl:orcl");
            Connection con = dataSource.getConnection();
            Properties props = new Properties();
            String fileName = "file.properties";
            in = new FileInputStream(fileName);
            props.load(in);

            // catalog 정보는 외부로부터 유입되는 정보
            String catalog = props.getProperty("catalog");
            // catalog 정보를 DB Connection 을 위해서 해당 값을 체크하지 않고, DB 카탈로그 정보에 지정함
            con.setCatalog(catalog); /* BUG */
            con.close();
        } catch (NamingException e) {}
        catch (SQLException e) {}
        catch (FileNotFoundException e) {}
        catch (IOException e) {}
        finally {
            try {
                if(in != null) in.close();
            } catch (IOException e) {}
        }
    }
    public String filter(String str) {return str;}

    int getSomeInt() { return 2;}
    String getCatalogData(HttpServletRequest props) {return props.getParameter("catalog");}
    public void testComplicated(HttpServletRequest req) {
        FileInputStream in = null;
        try {
            InitialContext ctx = new InitialContext();
            DataSource dataSource = (DataSource)ctx.lookup("jdbc:ocl:orcl");
            Connection con = dataSource.getConnection();
            Properties props = new Properties();
            String fileName = "file.properties";
            in = new FileInputStream(fileName);
            props.load(in);

            String catalog;
            if (getSomeInt() > 1) {
                // catalog 정보는 외부로부터 유입되는 정보
                catalog = getCatalogData(req);
            } else {
                catalog = "safe";
            }

            // catalog 정보를 DB Connection 을 위해서 해당 값을 체크하지 않고, DB 카탈로그 정보에 지정함
            con.setCatalog(catalog); /* BUG */
            con.close();
        } catch (NamingException e) {}
        catch (SQLException e) {}
        catch (FileNotFoundException e) {}
        catch (IOException e) {}
        finally {
            try {
                if(in != null) in.close();
            } catch (IOException e) {}
        }
    }
}
