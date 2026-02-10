import javax.ejb.*;
import java.io.Serializable;

public class Customer implements Serializable {
    private String firstName;
    private String lastName;

    public synchronized void setFirstName(String firstName) { // @violation
        //
    }
    public synchronized void setLastName(String lastName) { // @violation
        //
    }
}
