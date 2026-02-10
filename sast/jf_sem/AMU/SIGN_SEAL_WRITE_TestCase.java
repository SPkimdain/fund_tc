package amu;

import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SealedObject;
import java.io.*;
import java.security.*;
import java.util.HashMap;

public class SIGN_SEAL_WRITE_TestCase {
    HashMap test() throws IOException, ClassNotFoundException {
        // Build map
        HashMap<String, Integer> map = new HashMap();

        // Serialize map
        ObjectOutputStream out =
                new ObjectOutputStream(new FileOutputStream(""));
        out.writeObject(map); /* BUG */
        out.close();

        // Deserialize map
        ObjectInputStream in =
                new ObjectInputStream(new FileInputStream(""));
        map = (HashMap<String, Integer>) in.readObject(); /* BUG */ // resource leak by exception
        in.close();

        // Inspect map
        return map;
    }
    HashMap test2() throws Exception {
        // Build map
        HashMap<String, Integer> map = new HashMap();

        // Generate sealing key & seal map
        KeyGenerator generator;
        generator = KeyGenerator.getInstance("AES");
        generator.init(new SecureRandom());
        Key key = generator.generateKey();
        Cipher cipher = Cipher.getInstance("AES");
        cipher.init(Cipher.ENCRYPT_MODE, key);
        SealedObject sealedMap = new SealedObject(map, cipher);

        // Serialize map
        ObjectOutputStream out =
                new ObjectOutputStream(new FileOutputStream(""));
        out.writeObject(sealedMap); /* BUG */
        out.close();

        // Deserialize map
        ObjectInputStream in =
                new ObjectInputStream(new FileInputStream(""));
        sealedMap = (SealedObject) in.readObject(); /* BUG */ // resource leak by exception
        in.close();

        // Unseal map
        cipher = Cipher.getInstance("AES");
        cipher.init(Cipher.DECRYPT_MODE, key);
        map = (HashMap<String, Integer>) sealedMap.getObject(cipher);

        // Inspect map
        return map;
    }
    HashMap test3() throws Exception {
        HashMap<String, Integer> map = new HashMap();

        // Generate sealing key & seal map
        KeyGenerator generator;
        generator = KeyGenerator.getInstance("AES");
        generator.init(new SecureRandom());
        Key key = generator.generateKey();
        Cipher cipher = Cipher.getInstance("AES");
        cipher.init(Cipher.ENCRYPT_MODE, key);
        SealedObject sealedMap = new SealedObject(map, cipher);

        // Generate signing public/private key pair & sign map
        KeyPairGenerator kpg = KeyPairGenerator.getInstance("DSA");
        KeyPair kp = kpg.generateKeyPair();
        Signature sig = Signature.getInstance("SHA1withDSA");
        SignedObject signedMap =
                new SignedObject(sealedMap, kp.getPrivate(), sig); /* BUG */

        // Serialize map
        ObjectOutputStream out =
                new ObjectOutputStream(new FileOutputStream(""));
        out.writeObject(signedMap);
        out.close();

        // Deserialize map
        ObjectInputStream in =
                new ObjectInputStream(new FileInputStream(""));
        signedMap = (SignedObject) in.readObject(); /* BUG */ // resource leak by exception
        in.close();

        // Verify signature and retrieve map
        if (!signedMap.verify(kp.getPublic(), sig)) {
            throw new GeneralSecurityException("Map failed verification");
        }
        sealedMap = (SealedObject) signedMap.getObject();

        // Unseal map
        cipher = Cipher.getInstance("AES");
        cipher.init(Cipher.DECRYPT_MODE, key);
        map = (HashMap<String, Integer>) sealedMap.getObject(cipher);

        // Inspect map
        return map;
    }
    HashMap testSafe() throws Exception {
        HashMap<String, Integer> map = new HashMap();

        // Generate signing public/private key pair & sign map
        KeyPairGenerator kpg = KeyPairGenerator.getInstance("DSA");
        KeyPair kp = kpg.generateKeyPair();
        Signature sig = Signature.getInstance("SHA1withDSA");
        SignedObject signedMap = new SignedObject(map, kp.getPrivate(), sig);

        // Generate sealing key & seal map
        KeyGenerator generator;
        generator = KeyGenerator.getInstance("AES");
        generator.init(new SecureRandom());
        Key key = generator.generateKey();
        Cipher cipher = Cipher.getInstance("AES");
        cipher.init(Cipher.ENCRYPT_MODE, key);
        SealedObject sealedMap = new SealedObject(signedMap, cipher);

        // Serialize map
        ObjectOutputStream out =
                new ObjectOutputStream(new FileOutputStream(""));
        out.writeObject(sealedMap);
        out.close();

        // Deserialize map
        ObjectInputStream in =
                new ObjectInputStream(new FileInputStream(""));
        sealedMap = (SealedObject) in.readObject(); /* BUG */ // resource leak by exception
        in.close();

        // Unseal map
        cipher = Cipher.getInstance("AES");
        cipher.init(Cipher.DECRYPT_MODE, key);
        signedMap = (SignedObject) sealedMap.getObject(cipher);

        // Verify signature and retrieve map
        if (!signedMap.verify(kp.getPublic(), sig)) {
            throw new GeneralSecurityException("Map failed verification");
        }
        map = (HashMap<String, Integer>) signedMap.getObject();

        // Inspect map
        return map;
    }
}
