import java.io.File;
import java.util.*;
import java.util.jar.JarEntry;
import java.util.jar.JarFile;
import java.security.CodeSigner;

public class ImproperSignatureTestCase {
    public void BadMethod1(String downloadedFilePath, String downloadedExceptionFilePath) {
        File f2 = new File(downloadedExceptionFilePath);
        File f = new File(downloadedFilePath);
        JarFile jf = new JarFile(f);  // @violation
        JarFile jf2 = new JarFile(f2);
        Enumeration<JarEntry> ens = jf.entries();
        while(ens.asMoreElements()) {
            JarEntry en = ens.nextElement();
            if(!en.isDirectory()) {
                if(en.toString().equals(path)) {
                    CodeSigner[] signers = en.getCodeSigners();
                    //...
                }
            }
        }
        jf.close();
    }
    public void BadMethod2(String downloadedFilePath) {
        File f = new File(downloadedFilePath);
        JarFile jf = new JarFile(f, false);  // @violation
        Enumeration<JarEntry> ens = jf.entries();
        while(ens.asMoreElements()) {
            JarEntry en = ens.nextElement();
            if(!en.isDirectory()) {
                if(en.toString().equals(path)) {
                    CodeSigner[] signers = en.getCodeSigners();
                    //...
                }
            }
        }
        jf.close();
    }
    public void BadMethod3(String downloadedFilePath) {
        try (File f = new File(downloadedFilePath);
             JarFile jf = new JarFile(f);) {    // @violation
            Enumeration<JarEntry> ens = jf.entries();
            while(ens.asMoreElements()) {
                JarEntry en = ens.nextElement();
                if(!en.isDirectory()) {
                    if(en.toString().equals(path)) {
                        CodeSigner[] signers = en.getCodeSigners();
                        //...
                    }
                }
            }
        } catch (Exception e) {
            //...
        }
    }

    public void GoodMethod1(String downloadedFilePath) {
        File f = new File(downloadedFilePath);
        JarFile jf = new JarFile(f, true);
        Enumeration<JarEntry> ens = jf.entries();
        while(ens.asMoreElements()) {
            JarEntry en = ens.nextElement();
            if(!en.isDirectory()) {
                if(en.toString().equals(path)) {
                    CodeSigner[] signers = en.getCodeSigners();
                    //...
                }
            }
        }
        jf.close();
    }
    public void GoodMethod2(String downloadedExceptionFilePath) {
        File f = new File(downloadedExceptionFilePath);
        JarFile jf = new JarFile(f);
        Enumeration<JarEntry> ens = jf.entries();
        while(ens.asMoreElements()) {
            JarEntry en = ens.nextElement();
            if(!en.isDirectory()) {
                if(en.toString().equals(path)) {
                    CodeSigner[] signers = en.getCodeSigners();
                    //...
                }
            }
        }
        jf.close();
    }
    public void GoodMethod3(String downloadedFilePath) {
        try (File f = new File(downloadedFilePath);
             JarFile jf = new JarFile(f, true);) {
            Enumeration<JarEntry> ens = jf.entries();
            while(ens.asMoreElements()) {
                JarEntry en = ens.nextElement();
                if(!en.isDirectory()) {
                    if(en.toString().equals(path)) {
                        CodeSigner[] signers = en.getCodeSigners();
                        //...
                    }
                }
            }
        } catch (Exception e) {
            //...
        }
    }
}