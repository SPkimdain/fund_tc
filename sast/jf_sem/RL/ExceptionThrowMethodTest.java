package rl;

import java.io.*;

/**
 * User: starblood
 * Date: 5/14/13
 * Time: 3:20 PM
 */
public class ExceptionThrowMethodTest {
    public void saveAs(File dest) throws IOException {
        FileOutputStream fos = new FileOutputStream(dest);
        store(fos, null); /* BUG */ // Resource Leak, IOException thrown
        fos.close();
    }
    public void store(FileOutputStream fos, String header) throws IOException {
        OutputStreamWriter osw = new OutputStreamWriter(new FileOutputStream(new File("abc.txt")), "");
        osw.write("abc"); /* BUG */ // Resource Leak, IOException throw
        osw.close();
    }

    public void test() throws IOException {
        FileOutputStream out = new FileOutputStream("abc.txt");
        out.write(50); /* BUG */ // Resource Leak, IOException thrown
        out.close();
    }

    public void test2() throws IOException {
        BufferedOutputStream out = new BufferedOutputStream(new FileOutputStream("abc.txt"));
        out.write(209); /* BUG */ // Resource Leak, IOException throw
        out.close();
    }
    public void test3() throws IOException {
        OutputStreamWriter out = new OutputStreamWriter(new FileOutputStream("abc.txt"), "");
        out.write("abc"); /* BUG */ // Resource Leak, IOException throw
        out.close();
    }
}
