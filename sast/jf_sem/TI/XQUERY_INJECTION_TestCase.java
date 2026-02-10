package ti;

import javax.naming.Context;
import javax.naming.NamingException;
import javax.naming.directory.InitialDirContext;
import javax.xml.xquery.XQException;
import javax.xml.xquery.XQExpression;
import javax.xml.xquery.XQPreparedExpression;
import javax.xml.xquery.XQResultSequence;
import java.util.Hashtable;
import java.util.Properties;
import javax.servlet.http.HttpServletRequest;

/**
 * Writer: Gyuhang Shim
 * Date: 7/20/12
 */
/* OPT : -show_followers */
public class XQUERY_INJECTION_TestCase {
    @SuppressWarnings("unchecked")
    public void query(HttpServletRequest request, XQExpression xqExpression) throws NamingException, XQException {
        Properties props = new Properties();
        // 외부로 부터 입력을 받음
        String name = request.getParameter("name"); //String name = props.getProperty("name");
        Hashtable env = new Hashtable();
        env.put(Context.INITIAL_CONTEXT_FACTORY, "com.sun.jndi.ldap.LdapCtxFactory");
        env.put(Context.PROVIDER_URL, "ldap://localhost:389/o=rootDir");
        javax.naming.directory.DirContext ctx = new InitialDirContext(env);
        javax.xml.xquery.XQDataSource xqds = (javax.xml.xquery.XQDataSource)ctx.lookup("xqj/personnel");
        javax.xml.xquery.XQConnection conn = xqds.getConnection();

        String es = "doc('users.xml')/userlist/user[uname='" + name + "']";
        // 입력값이 XQuery 의 인자로 사용
        XQPreparedExpression expr = conn.prepareExpression(es); /* BUG */
        XQResultSequence result = expr.executeQuery();
        while (result.next()) {
            String str = result.getAtomicValue();
            if (str.indexOf('>') < 0) {
                System.out.println(str);
            }
        }
        xqExpression.executeQuery(es); /* BUG */
    }
}
