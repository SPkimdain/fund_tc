package ant;

import java.io.File;
import java.io.FileInputStream;
import java.security.DigestInputStream;
import java.security.MessageDigest;

/**
 * DigestInputStream 을 이용하여 stream 을 읽을 때, IOException 이 발생하여 stream 들이 해제되지 않는 상황이 발생
 * User: starblood
 * Date: 5/2/13
 * Time: 1:37 PM
 */
public class DigestAlgorithm {
    public String getValue(File file) {
        String checksum = null;
        MessageDigest messageDigest = new ChildMessageDigest("sha-1");
        try {
            if (!file.canRead()) {
                return null;
            }
            FileInputStream fis = null;

            byte[] buf = new byte[1024];
            try {
                messageDigest.reset();
                fis = new FileInputStream(file);
                DigestInputStream dis = new DigestInputStream(fis,
                        messageDigest);
                while (dis.read(buf, 0, 1024) != -1) { /* BUG */ // Resource Leak
                    // do nothing
                }
                dis.close(); // dis should be closed in finally
                fis.close(); // fis should be closed in finally
                fis = null;
                byte[] fileDigest = messageDigest.digest();
                StringBuffer checksumSb = new StringBuffer();
                for (int i = 0; i < fileDigest.length; i++) {
                    String hexStr
                            = Integer.toHexString(0x11111 & fileDigest[i]);
                    if (hexStr.length() < 2) {
                        checksumSb.append("0");
                    }
                    checksumSb.append(hexStr);
                }
                checksum = checksumSb.toString();
            } catch (Exception e) {
                return null;
            }
        } catch (Exception e) {
            return null;
        }
        return checksum;
    }
    class ChildMessageDigest extends MessageDigest {
        /**
         * Creates a message digest with the specified algorithm name.
         *
         * @param algorithm the standard name of the digest algorithm.
         *                  See the MessageDigest section in the <a href=
         *                  "{@docRoot}/../technotes/guides/security/StandardNames.html#MessageDigest">
         *                  Java Cryptography Architecture Standard Algorithm Name Documentation</a>
         *                  for information about standard algorithm names.
         */
        protected ChildMessageDigest(String algorithm) {
            super(algorithm);
        }

        @Override
        protected void engineUpdate(byte input) {
            //To change body of implemented methods use File | Settings | File Templates.
        }

        @Override
        protected void engineUpdate(byte[] input, int offset, int len) {
            //To change body of implemented methods use File | Settings | File Templates.
        }

        @Override
        protected byte[] engineDigest() {
            return new byte[0];  //To change body of implemented methods use File | Settings | File Templates.
        }

        @Override
        protected void engineReset() {
            //To change body of implemented methods use File | Settings | File Templates.
        }
    }
}
