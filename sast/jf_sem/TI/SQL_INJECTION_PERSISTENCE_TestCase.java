package ti;

import helper.EntityManagerImpl;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.List;
import java.util.Properties;

import javax.persistence.EntityManager;
import javax.persistence.Query;

import javax.servlet.ServletContextEvent;
import javax.servlet.ServletContextListener;

import javax.servlet.http.HttpServletRequest;

/**
 * SQL Injection Persistence test case
 * Writer: Gyuhang Shim
 */
/* OPT : -show_followers */
public class SQL_INJECTION_PERSISTENCE_TestCase implements ServletContextListener {
    @SuppressWarnings("unchecked")
    public List<?> getAllItemsInWildcardCollection(HttpServletRequest request) {
        EntityManager em = getEntityManager();
        List<SQL_INJECTION_PERSISTENCE_TestCase> r_type = null;
        FileInputStream in = null;
        try {
            Properties props = new Properties();
            String fileName = "conditions.txt";
            in = new FileInputStream(fileName);
            props.load(in);

            // 외부로 부터 입력을 받는다. tainted
            String id = request.getParameter("id");//String id = props.getProperty("id");
            /*
                외부 입력 값이 query 의 인자로 사용이 된다.
                javax.persistence.Query, javax.persistence.EntityManager.createNativeQuery
             */
            Query query = em.createNativeQuery("SELECT OBJECT(i) FROM Item i WHERE i.itemID>" + id); /* BUG */
            List<SQL_INJECTION_PERSISTENCE_TestCase> items = query.getResultList();
            // ...

            em.createNamedQuery(id); /* BUG */
            em.createQuery(id); /* BUG */
            return r_type;
        } catch (Exception e) {
            return null;
        } finally {
            try {
                if(in != null) in.close();
            } catch (IOException e) {}
        }
    }
    public void contextInitialized(ServletContextEvent servletContextEvent) {}
    public void contextDestroyed(ServletContextEvent servletContextEvent) {}

    private EntityManager getEntityManager() {
        return new EntityManagerImpl();
    }
}
