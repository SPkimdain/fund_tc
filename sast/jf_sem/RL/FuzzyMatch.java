package rl;

import java.io.*;

public class FuzzyMatch {
    void foo() {
        BufferedInputStream is = null;
        try {
            is = new BufferedInputStream(new FileInputStream(new File("")));
            System.out.println("hello");
        }
        catch(IOException e) { }
        finally {
            FileUtils.close(is);
        }
    }
    void bar() {
        BufferedInputStream is = null;
        try {
            is = new BufferedInputStream(new FileInputStream(new File("")));
            System.out.println("hello");
        }
        catch(IOException e) { }
        finally {
            // empty
        }
    } /* BUG */
    void customStreamTest() {
        try {
            InputStream in = new FileInputStream(new File(""));
            CustomStream cs = new CustomStream(in);
            System.out.println("hey");
            cs.close();
        } catch (FileNotFoundException e) {}
    }

    // Closable interface
    public void test2() {
        FileInputStream fis = null;
        try {
            fis = new FileInputStream(new File("test.txt"));
        }
        catch (Exception e) { }
        finally {
            if (fis != null) {
                myClose(fis);
            }
        }
    }

    private void myClose(Closeable closeable) {
        if (closeable != null) {
            try {
                closeable.close();
            }
            catch (IOException e) {}
        }
    }
}

class CustomStream {
    InputStream is = null;
    CustomStream(InputStream is) {
        this.is = is;
    }
    void close() {
        try {
            if(is != null) is.close();
        } catch (IOException e) {}
    }
}