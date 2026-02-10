package basic;

import javax.naming.Context;
import java.lang.String;
import java.util.Map;

/**
 * Writer: Gyuhang Shim
 * Date: 4/24/12
 */
public class ImproperAuthorization {

    public Map<String, String> getEnv() {
        Map<String, String> envMap = new Map<String, String>();
        // Do someething ...
        return envMap;
    }

    public void authorize(String sSingleId, int iFlag, String sServiceProvider, String sUid, String sPwd) {
        Map<String, String> env = System.getenv();
        Map env2 = getEnv();
		String noneString = "none";
		String authentication = Context.SECURITY_AUTHENTICATION;
        // do something
        env.put(Context.INITIAL_CONTEXT_FACTORY, "an_factory");
        env.put(Context.PROVIDER_URL, sServiceProvider);
        // 익명으로 LDAP 인증을 사용
        env.put(javax.naming.Context.SECURITY_AUTHENTICATION, "none"); // @violation
		env2.put(Context.SECURITY_AUTHENTICATION, noneString); // @violation
		env.put(authentication, "none"); // @violation
		System.getenv().put(authentication, "none"); // @violation
		env2.put(Context.SECURITY_AUTHENTICATION, "safe");
        env.put(Context.SECURITY_PRINCIPAL, sUid);
        env.put(Context.SECURITY_CREDENTIALS, sPwd);
        // ...
    }

    public void bad(HttpServletRequest request, HttpServletResponse response) throws Throwable
    {
        String data;


        data = "passwd";


        String username = request.getParameter("username");
        String password = request.getParameter("password");
        String msgId = request.getParameter("msgId");
        if (username == null || password == null || !KrdUtil.isAuthenticatedUser(username, password))
        {
            throw new Exception("Invalid username, password");
        }
        if (msgId == null)
        {
            throw new Exception("Invalid msgId");
        }
        KrdMessage msg = KrdUtil.LookupKrdMessageObject(msgId);
        /* FLAW */
        if (msg != null) {
            response.getWriter().println("From: " + msg.getUserName()); // @violation
            response.getWriter().println("Subject: " + msg.getSubField()); // @violation
            response.getWriter().println("Body: " + msg.getBodyField()); // @violation
        }

        if (msg != null && msg.getUserName().equals(username)) {
            response.getWriter().println("From: " + msg.getUserName());
            response.getWriter().println("Subject: " + msg.getSubField());
            response.getWriter().println("Body: " + msg.getBodyField());
        }

        KrdMessage msg2 = krdUtil.LookupKrdMessageObject(msgId + "1");
        if(msg != null && msg2 != null && msg2.getUserName().equals(username)) {
            response.getWriter().println("From: " + msg.getUserName()); // @violation
            response.getWriter().println("Subject: " + msg.getSubField()); // @violation
            response.getWriter().println("Body: " + msg.getBodyField()); // @violation
        }
    }
}
