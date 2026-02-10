package security;

import java.lang.String;

public class ForbiddenReplacingEmailAddress {

    public void process(String email) {
        // Do something ...
    }

    public void work(String email, String id) {
        process(email);
        email = "newmail@newmail.com"; // @violation
        process(email);
    }

    public void work2(String email, String id) {
        String emailbuf = email;
        emailbuf = "newmail@newmail.com";
        process(email);
    }
}
