package ti;

import java.io.BufferedReader;
import java.io.IOException;
import java.lang.String;

public class EXISTING_PASSWORD_RECOVERY_TestCase {

    /** Password field */
    public String password;

    public void recover(BufferedReader reader, boolean cond) {
        try {
            // Read the existing password from file and directly recover
            String existingPassword = reader.readLine();
            // Do something ...
            password = existingPassword; /* BUG */
            // ...
        } catch(IOException ioe) {
            ioe.printStackTrace();
        }
    }
}
