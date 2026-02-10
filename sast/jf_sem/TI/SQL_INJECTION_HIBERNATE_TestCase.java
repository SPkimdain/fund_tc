package ti;

import org.hibernate.Query;
import org.hibernate.Session;
import org.hibernate.StatelessSession;
import org.hibernate.cfg.Configuration;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Properties;

import javax.servlet.http.HttpServletRequest;

/**
 * Writer: Gyuhang Shim
 * Date: 7/17/12
 * SQL_INJECTION_HIBERNATE test case
 */
/* OPT : -show_followers */
public class SQL_INJECTION_HIBERNATE_TestCase {
    @SuppressWarnings("deprecation")
    public void listHistory(HttpServletRequest request, StatelessSession statelessSession) {
        Session session = new Configuration().configure().buildSessionFactory().openSession();
        FileInputStream in = null;
        try {
			String str = "abcd";
            Properties props = new Properties();
            String fileName = "Hibernate.properties";
            in = new FileInputStream(fileName);
            props.load(in);
            // 외부로부터 입력을 받음
            String idValue = request.getParameter("idLow");//String idValue = props.getProperty("idLow");
            // 외부 입력을 검증없이 SQL query 문의 인자로 사용한다.
            Query query1 = session.createQuery("from Address a where a.name='" + idValue); /* BUG */
            Query query2 = session.createQuery("from Address a where a.name='" + str); /* SAFE */
            Query query3 = session.createSQLQuery("from Address a where a.name='" + idValue); /* BUG */
            Query query4 = statelessSession.createQuery("from Address a where a.name='" + idValue); /* BUG */
            Query query5 = statelessSession.createSQLQuery("from Address a where a.name='" + idValue); /* BUG */

            query1.list();
            query2.list();
            query3.list();
            query4.list();
            query5.list();
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
