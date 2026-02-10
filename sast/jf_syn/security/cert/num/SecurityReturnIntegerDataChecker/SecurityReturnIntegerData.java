package cert.num;

import java.io.DataInputStream.*;

class SecurityReturnIntegerData {
    public static long getInteger(DataInputStream is) throws IOException {

        int int_var = 0;
        long long_var = 0;

        long_var = is.readInt();                // @violation
        long_var = is.readInt() & 0xFFFFFFFFL;  /* Safe */
        int_var = is.readInt();                 // @violation
        int_var = is.readInt() & 0xFFFFFFFFL;   // @violation

        boolean flag = true;

        if(flag) {
            return is.readInt();                // @violation
        } else {
            return is.readInt() & 0xFFFFFFFFL;  /* Safe */
        }
    }
}