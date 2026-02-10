package cc;

import java.net.InetAddress;
import java.net.UnknownHostException;

public class InetAddressBad1 {
    void func() {
        InetAddress iNet = null;
        InetAddress[] iNetArr = null;
        byte[] b = new byte[2];
        try {
            iNet = InetAddress.getByName("Host Name");          // @violation
            iNetArr = InetAddress.getAllByName("Host Name");    // @violation
            iNet = InetAddress.getByAddress(b);                 // @violation
        } catch(UnknownHostException e) {
            /* do something */
        }
    }
}