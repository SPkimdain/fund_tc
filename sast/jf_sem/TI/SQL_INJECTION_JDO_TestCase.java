package ti;

import helper.Contact;
import helper.ContactDAO;

import javax.jdo.PersistenceManager;
import javax.jdo.PersistenceManagerFactory;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.List;
import java.util.Properties;

import javax.servlet.http.HttpServletRequest;

/* OPT : -show_followers */
public abstract class SQL_INJECTION_JDO_TestCase implements ContactDAO {
    @SuppressWarnings("unchecked")
    public List<Contact> listContacts(HttpServletRequest request) {
        PersistenceManager pm = getPersistenceManagerFactory().getPersistenceManager();/* BUG */ // ND
        String query = "select from " + Contact.class.getName();
        Properties props = null;
        String fileName = null;
        FileInputStream in = null;
        try {
            props = new Properties();
            fileName = "contacts.txt";
            in = new FileInputStream(fileName);
            if (in != null) {
                props.load(in);
            }
            in.close();
            // 외부로부터 입력을 받는다.
            String name = request.getParameter("name");//String name = props.getProperty("name"); /* tainted input, name comes in */
            if (name != null) {
                query += " where name = '" + name + "'"; /* tainted input, query */
            }
        } catch (IOException e) {

        } finally {
            if (in != null) {
                try {
                    in.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
        // 외부 입력값이 JDO 객체의 인자로 사용된다.
        return (List<Contact>) pm.newQuery(query).execute(); /* BUG */
    }

    @SuppressWarnings("unchecked")
    public List<Contact> listContacts2(HttpServletRequest request) {
        PersistenceManager pm = getPersistenceManagerFactory().getPersistenceManager(); /* BUG */ // ND
        String query = "select from " + Contact.class.getName();
        Properties props = null;
        String fileName = null;
        FileInputStream in = null;
        try {
            props = new Properties();
            fileName = "contacts.txt";
            in = new FileInputStream(fileName);
            if (in != null) {
                props.load(in);
            }
            // 외부로부터 입력을 받는다.
            String name = request.getParameter("name");//String name = props.getProperty("name"); /* tainted input, name comes in */
            if (name != null) {
                query += " where name = '" + name + "'"; /* tainted input, query */
            }
        } catch (IOException e) {

        } finally {
            if (in != null) {
                try {
                    in.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

        String[] splittedQuery = query.split(".");
        String subQuery = splittedQuery[0].substring(1);

        // 외부 입력값이 JDO 객체의 인자로 사용된다.
        return (List<Contact>) pm.newQuery(subQuery).execute(); /* BUG */
    }

    public PersistenceManagerFactory getPersistenceManagerFactory() {
        return null;
    }
}
