package rl;

import java.io.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

/**
 * User: starblood
 * Date: 5/8/13
 * Time: 2:51 PM
 */
public class ExceptionThrowTest {
    public void foo() throws IOException {
        File file = new File("haha");
        ObjectInputStream ois = null;
        try {
            ois = new ObjectInputStream(new FileInputStream(file));
            Object obj = ois.readObject();
        } catch (ClassNotFoundException e) {
        } catch (FileNotFoundException e) {
        } catch (IOException e) {
        } finally {
            if(ois != null) {
                ois.close(); // safe
            }
        }
    }

    public void foo2(String name, String pwd, String query) {
        Connection sConn = null;
        Statement stmt = null;
        ResultSet rs = null;

        try {
            sConn = DriverManager.getConnection("jdbc:oracle:thin:1521:ora9", name, pwd);
            // 여기서 exception발생
            stmt = sConn.createStatement();
            rs = stmt.executeQuery(query);
            while(rs.next()) {
            }
        }catch(Exception e) {
            int a = 1;
        }
        finally {
            // escaped by Exception
            // escaped by Exception
            // assume re != null is true
            // CLUE_RESOURCE_DANGLED <- 아래에서 Exception을 받아서 아무일도 하지 않으니 sConn은 close되어야 함
            if(rs != null) try { rs.close(); } catch(Exception e) {} // safe
            if(sConn != null) try {sConn.close();} catch(Exception e) {} // safe
        }
    } /* BUG */ // resource leak

    public String foo3(String filename) throws Exception
    {
        BufferedReader in = null;
        StringBuffer strbuf = null;
        try {
            File sourceFile = new File(filename);
            in = new BufferedReader(new FileReader(sourceFile)); //  여기서 resource alloc
            strbuf = new StringBuffer(2048);
            String str = "";
    /* finch message
     [EXCEPTION] escaped by exception
     [EXCEPTION] escaped by exception
     [ASSUME $r3!=null is true]Goto line 282 */
            while((str = in.readLine()) != null) { // 여기서 CLUE_RESOURCE_DANGLED
                strbuf.append(str+"\n");
            }
        }
        catch(Exception e) {
            if (in != null) in.close();
            strbuf = null;
            throw e;
        }

        return "haha"; /* BUG */ // Resource Leak
    }

    public String foo3_safe(String filename) throws Exception
    {
        BufferedReader in = null;
        StringBuffer strbuf = null;
        try {
            File sourceFile = new File(filename);
            in = new BufferedReader(new FileReader(sourceFile)); //  여기서 resource alloc
            strbuf = new StringBuffer(2048);
            String str = "";
    /* finch message
     [EXCEPTION] escaped by exception
     [EXCEPTION] escaped by exception
     [ASSUME $r3!=null is true]Goto line 282 */
            while((str = in.readLine()) != null) { // 여기서 CLUE_RESOURCE_DANGLED
                strbuf.append(str+"\n");
            }
        }
        catch(Exception e) {
            if (in != null) in.close();
            strbuf = null;
            throw e;
        } finally {
            in.close(); // safe
        }

        return "haha";
    }
}
