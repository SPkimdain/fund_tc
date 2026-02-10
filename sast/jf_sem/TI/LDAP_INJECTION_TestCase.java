package ti;

import javax.naming.Context;
import javax.naming.NamingEnumeration;
import javax.naming.NamingException;
import javax.naming.directory.InitialDirContext;
import javax.naming.directory.SearchControls;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Hashtable;
import java.util.Properties;
import javax.servlet.http.HttpServletRequest;

/**
 * Writer: Gyuhang Shim
 * Date: 5/2/12
 */
/* OPT : -show_followers */
public class LDAP_INJECTION_TestCase {
    @SuppressWarnings("unchecked")
    public void test(HttpServletRequest request) {
        Hashtable env = new Hashtable();
        env.put(Context.INITIAL_CONTEXT_FACTORY, "com.sun.jndi.ldap.LdapCtxFactory");
        env.put(Context.PROVIDER_URL, "ldap://localhost:389/o=rootDir");
        FileInputStream in = null;
        try {
            javax.naming.directory.DirContext ctx = new InitialDirContext(env);
            // 프로퍼티를 만들고 외부 파일을 로드한다.
            Properties props = new Properties();
            String fileName = "ldap.properties";
            in = new FileInputStream(fileName);
            props.load(in);
            // LDAP Search 를 하기 위해 name 을 읽는다.
            String name = props.getProperty("name");
            name = request.getParameter("name");
            String filter = "(name = " + name + ")";
            // LDAP search 가 name 값에 대한 여과없이 그대로 통과되어 검색이 되어진다.
            NamingEnumeration answer = ctx.search("ou=NewHires", filter, new SearchControls()); /* BUG */
            printSearchEnumeration(answer);

            String safeFilter1 = filter.replace('\n', 's');
            NamingEnumeration safeAnswer1 = ctx.search("ou=NewHires", safeFilter1, new SearchControls()); /* SAFE */
            printSearchEnumeration(safeAnswer1);

            String safeFilter2 = filter.replace("\n", "");
            NamingEnumeration safeAnswer2 = ctx.search("ou=NewHires", safeFilter2, new SearchControls()); /* SAFE */
            printSearchEnumeration(safeAnswer2);

            String safeFilter3 = filter.replaceAll("\n", "");
            NamingEnumeration safeAnswer3 = ctx.search("ou=NewHires", safeFilter3, new SearchControls()); /* SAFE */
            printSearchEnumeration(safeAnswer3);

            String safeFilter4 = filter.replaceFirst("\n", "");
            NamingEnumeration safeAnswer4 = ctx.search("ou=NewHires", safeFilter4, new SearchControls()); /* SAFE */
            printSearchEnumeration(safeAnswer4);

            String taintName1 = name;
            if (taintName1.indexOf("&") != -1) { /* BUG 2 */ //NULL_RETURN_STD
                ctx.search("ou=NewHires", taintName1, new SearchControls()); /* SAFE */
            }

            String taintName2 = name;
            if (taintName2.indexOf("<") != -1) { /* BUG 2 */ //NULL_RETURN_STD
                ctx.search("ou=NewHires", taintName2, new SearchControls()); /* SAFE */
            }

            String taintName3 = name;
            if (taintName3.indexOf(">") != -1) { /* BUG 2 */ //NULL_RETURN_STD
                ctx.search("ou=NewHires", taintName3, new SearchControls()); /* SAFE */
            }

            ctx.close();
        } catch (NamingException e) {
            e.printStackTrace();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if(in != null) in.close();
            } catch (IOException e) {}
        }
    }

    private void printSearchEnumeration(NamingEnumeration answer) {
    }

    int getAnotherInt() {return -1;}
    String getFilter (String name) {
        return "(name = " + name + ")";
    }
    @SuppressWarnings("unchecked")
    public void testComplicated(HttpServletRequest request) {
        Hashtable env = new Hashtable();
        env.put(Context.INITIAL_CONTEXT_FACTORY, "com.sun.jndi.ldap.LdapCtxFactory");
        env.put(Context.PROVIDER_URL, "ldap://localhost:389/o=rootDir");
        FileInputStream in = null;
        try {
            javax.naming.directory.DirContext ctx = new InitialDirContext(env);
            // 프로퍼티를 만들고 외부 파일을 로드한다.
            Properties props = new Properties();
            String fileName = "ldap.properties";
            in = new FileInputStream(fileName);
            props.load(in);
            // LDAP Search 를 하기 위해 name 을 읽는다.
            String name = props.getProperty("name"); // tainted
            name = request.getParameter("name");
            String filter = getFilter(name); // tainted value go to getFilter
            if (getAnotherInt() < 0) {
                ctx.search("ou=NewHires", filter, new SearchControls()); /* BUG */
            } else {
                ctx.search("ou=NewHires", "defs", new SearchControls());
            }


            ctx.close();
        } catch (NamingException e) {
            e.printStackTrace();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if(in != null) in.close();
            } catch (IOException e) {}
        }
    }
}
