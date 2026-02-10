package security;

import com.sun.org.apache.xml.internal.security.exceptions.Base64DecodingException;
import com.sun.org.apache.xml.internal.security.utils.Base64;

import javax.crypto.Cipher;
import javax.crypto.NoSuchPaddingException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Properties;

/**
 * Writer: Gyuhang Shim
 * Date: 9/14/12
 */
public class USING_WEAK_CRYPTOGRAPHIC_ALGORITHM_TestCase {
    public void test(Properties prop) {
        try {
            Cipher c = Cipher.getInstance("DES"); // @violation
            Cipher c2 = Cipher.getInstance("AES/CBS/PKCS5Padding"); /* SAFE */
            byte [] password = Base64.decode(prop.getProperty("password")); // @violation
            MessageDigest md1 = MessageDigest.getInstance("MD5"); // @violation
            MessageDigest md2 = java.security.MessageDigest.getInstance("SHA1", "SUN"); // @violation

            String des = "DES";
            Cipher c3 = Cipher.getInstance(des); // @violation
        } catch (NoSuchAlgorithmException e) {

        } catch (NoSuchPaddingException e) {

        } catch (Base64DecodingException e) {

        }
    }

}
