package basic;

import java.io.*;

/**
 * Writer: Gyuhang Shim
 * Date: 4/2/12
 */
public class MethodIgnoresReturnValue {
    public void testString() {
        String str = "abcdefg";
        str.trim(); // @violation
    }

    public void testFile() {
        try {
            File file = new File("abcd.txt");
            FileInputStream fis = new FileInputStream(file);
            // read() method 의 return 값을 무시하였다.
            fis.read(); // @violation

            BufferedInputStream bis = new BufferedInputStream(fis);
            bis.read(); // @violation

            FileReader fr = new FileReader(file);
            fr.read(); // @violation

            BufferedReader br = new BufferedReader(fr);
            br.read(); // @violation

            ByteArrayInputStream bais = new ByteArrayInputStream(new byte[1024]);
            bais.read(); // @violation

            CharArrayReader car = new CharArrayReader(new char[1024]);
            car.read(); // @violation

            DataInputStream dis = new DataInputStream(fis);
            dis.read(); // @violation

            FilterReader fr2 = new FilterReader(fr) {
                @Override
                public int read() throws IOException {
                    return super.read();    //To change body of overridden methods use File | Settings | File Templates.
                }
            };
            fr2.read(); // @violation

            InputStream is = new InputStream() {
                @Override
                public int read() throws IOException {
                    return 0;  //To change body of implemented methods use File | Settings | File Templates.
                }
            };
            is.read(); // @violation

            LineNumberInputStream lnis = new LineNumberInputStream(is);
            lnis.read(); // @violation

            LineNumberReader lnr = new LineNumberReader(fr);
            lnr.read(); // @violation

            ObjectInputStream ois = new ObjectInputStream(is);
            ois.read(); // @violation

            PipedInputStream pis = new PipedInputStream();
            pis.read(); // @violation

            PushbackInputStream pis2 = new PushbackInputStream(is);
            pis2.read(); // @violation

            PushbackReader pr = new PushbackReader(fr);
            pr.read(); // @violation

            RandomAccessFile raf = new RandomAccessFile("abc.txt", "abc");
            raf.read(); // @violation

            SequenceInputStream sis = new SequenceInputStream(is, is);
            sis.read(); // @violation

            StringBufferInputStream sbis = new StringBufferInputStream("abc");
            sbis.read(); // @violation

            StringReader sr = new StringReader("abc");
            sr.read(); // @violation
        } catch (FileNotFoundException e) {
            System.out.println(e);
        } catch (IOException e) {
            System.out.println(e);
        }
    }

    public void testFile1() {
        try (StringBufferInputStream sbis = new StringBufferInputStream("abc")) {
            sbis.read(); // @violation

            SequenceInputStream sis = new SequenceInputStream(is, is);
            sis.read(); // @violation

        } catch (FileNotFoundException e) {
            System.out.println(e);
        } catch (IOException e) {
            System.out.println(e);
        }
    }

    public void lambdaFunc1(String command) {
        Consumer<String> consumer = s -> {
            StringBufferInputStream sbis = new StringBufferInputStream("abc");
            sbis.read();    // @violation
        };
        consumer.accept(command);
    }

    public void lambdaFunc2(String command) {
        StringBufferInputStream sbis = new StringBufferInputStream("abc");

        Consumer<String> consumer = () -> {
            sbis.read();    // @violation
        };
        consumer.accept(command);
    }
}
