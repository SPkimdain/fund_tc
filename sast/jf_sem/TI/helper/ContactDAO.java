package ti.helper;

import javax.jdo.PersistenceManager;
import javax.jdo.PersistenceManagerFactory;
import java.util.List;
/**
 * Writer: Gyuhang Shim
 * Date: 4/16/12
 */
public interface ContactDAO extends PersistenceManager, PersistenceManagerFactory {
    public List<Contact> listContacts();
}
