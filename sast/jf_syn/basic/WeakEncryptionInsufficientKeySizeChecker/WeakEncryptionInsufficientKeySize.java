package basic;

import java.security.KeyPair;
import java.security.KeyPairGenerator;

public class WeakEncryptionInsufficientKeySize {
    int keySize = 512;

    public void unsafe() throws Exception {
        int ks = 511;
        int ks2 = 11;

        KeyPairGenerator keyPairGenerator1 = KeyPairGenerator.getInstance("AES");
        keyPairGenerator1.initialize(ks2 + 2, null); // @violation

        KeyPairGenerator keyPairGenerator2 = KeyPairGenerator.getInstance("SEED");
        keyPairGenerator2.initialize(64, null); // @violation

        KeyPairGenerator keyPairGenerator3 = KeyPairGenerator.getInstance("RSA");
        keyPairGenerator3.initialize(512, null); // @violation
        keyPairGenerator3.initialize(ks + keySize); // @violation
        keyPairGenerator3.initialize(keySize); // @violation

        KeyPairGenerator keyPairGenerator4 = KeyPairGenerator.getInstance("EC");
        keyPairGenerator4.initialize(ks2, null); // @violation
    }

    public void safe() throws Exception {
        KeyPairGenerator keyPairGenerator = KeyPairGenerator.getInstance("SHA-1");
        keyPairGenerator.initialize(128, null);
        KeyPair keyPair = keyPairGenerator.generateKeyPair();
    }
}
