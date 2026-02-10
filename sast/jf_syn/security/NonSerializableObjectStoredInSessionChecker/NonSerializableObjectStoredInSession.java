package security;

import java.io.Serializable;
import javax.servlet.http.HttpSession;

public class DataGlob {
    String globName;
    String globValue;
    public void addToSession(HttpSession session) {
        session.setAttribute("glob", this); // @violation
    }
}