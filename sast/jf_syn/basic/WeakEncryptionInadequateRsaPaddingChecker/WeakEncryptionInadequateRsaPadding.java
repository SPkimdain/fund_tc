package basic;

import javax.crypto.Cipher;

public class WeakEncryptionInadequateRsaPadding {
    private static final String RSA="RSA/NONE/NoPadding";
    private static Cipher cipher;

    static {
        try {
            cipher=javax.crypto.Cipher.getInstance("RSA/NONE/NoPadding", new sun.security.provider.Sun()); // @violation
        } catch(Exception e) {}
    }

    public WEAK_ENCRYPTION_INADEQUATE_RSA_PADDING_TestCase() throws Exception {
        cipher=javax.crypto.Cipher.getInstance(RSA); // @violation
    }

    public Cipher getUnsafeCipher1() throws Exception {
        return javax.crypto.Cipher.getInstance(RSA, new sun.security.provider.Sun()); // @violation
    }

    public Cipher getUnsafeCipher2() throws Exception {
        Cipher cipher1=Cipher.getInstance("RSA/NONE/NoPadding"); // @violation
        return cipher1;
    }

    public Cipher getSafeCipher() throws Exception {
        return Cipher.getInstance("RSA/CBC/PKCS5Padding");
    }
}
