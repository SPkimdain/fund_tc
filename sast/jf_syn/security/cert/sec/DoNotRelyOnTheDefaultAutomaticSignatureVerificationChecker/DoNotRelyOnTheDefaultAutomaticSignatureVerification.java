import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.security.GeneralSecurityException;
import java.security.KeyStore;
import java.security.cert.Certificate;
import java.net.URLClassLoader;
import java.net.URL;

public class DoNotRelyOnTheDefaultAutomaticSignatureVerification extends URLClassLoader {
    private URL url;
    public DoNotRelyOnTheDefaultAutomaticSignatureVerification(URL url) {
        super(new URL[] { url });
        this.url = url;
    }
    @SuppressWarnings("unchecked")
    public void invokeClass(String name, String[] args)
            throws ClassNotFoundException, NoSuchMethodException,
            InvocationTargetException {
        Class c = loadClass(name);
        Method m = c.getMethod("main", new Class[] { args.getClass() });
        m.setAccessible(true);
        int mods = m.getModifiers();
        if (m.getReturnType() != void.class || !Modifier.isStatic(mods) ||
                !Modifier.isPublic(mods)) {
            throw new NoSuchMethodException("main");
        }
        try {
            m.invoke(null, new Object[] { args }); // @violation
        } catch (IllegalAccessException e) {
            System.out.println("Access denied");
        }
    }
    @SuppressWarnings("unchecked")
    public void invokeClassSafe(String name, String[] args)
            throws ClassNotFoundException, NoSuchMethodException,
            InvocationTargetException, GeneralSecurityException,
            IOException {
        Class c = loadClass(name);
        Certificate[] certs = // violation // NULL_RETURN_STD (null from getCodeSource)
                c.getProtectionDomain().getCodeSource().getCertificates();
        if (certs == null) {
            // return, do not execute if unsigned
            System.out.println("No signature!");
            return;
        }

        KeyStore ks = KeyStore.getInstance("JKS");
        ks.load(new FileInputStream(System.getProperty(
                        "user.home"+ File.separator + "keystore.jks")),
                "loadkeystorepassword".toCharArray());
        // user is the alias
        Certificate pubCert = ks.getCertificate("user");
        // check with the trusted public key, else throws exception
        certs[0].verify(pubCert.getPublicKey()); // violation // NULL_RETURN_STD (null from getCertificate)

        Method m = c.getMethod("main", new Class[] { args.getClass() });
        m.setAccessible(true);
        int mods = m.getModifiers();
        if (m.getReturnType() != void.class || !Modifier.isStatic(mods) ||
                !Modifier.isPublic(mods)) {
            throw new NoSuchMethodException("main");
        }
        try {
            m.invoke(null, new Object[] { args });
        } catch (IllegalAccessException e) {
            System.out.println("Access denied");
        }
    }
}
