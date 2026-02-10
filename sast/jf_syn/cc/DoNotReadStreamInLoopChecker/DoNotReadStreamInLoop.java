package cc;

import org.apache.tools.ant.filters.StringInputStream;

import java.io.*;

public class DoNotReadStreamInLoop {

    int i, len=0;
    InputStream in=null;
    OutputStream out=null;

    public void func() {
        int i, s=0;

        try {
            in = new FileInputStream(new File(args[0]));
            out = new FileOutputStream(args[1], true);
        } catch(FileNotFoundException e) {
            System.out.println(e);
        } catch(IOException e) {
            System.out.println(e);
        }

        try {
            while((i=in.read()) != -1) { // @violation
                out.write(i);
                len++;
            }
            in.close();
            out.close();
            System.out.println(len+" bytes are copied...Successfully!");
        } catch(IOException e1) {
            System.out.println(e1);
        }

        try {
            in = new StringInputStream(new File(args[0]));
            out = new StringOutputStream(args[1], true);
        } catch(FileNotFoundException e) {
            System.out.println(e);
        } catch(IOException e) {
            System.out.println(e);
        }

        while(i < 20) {
            i=in.read(); // @violation
            s += noLock();
            i++;
        }

        try {
            in = new BufferedInputStream(new File(args[0]));
            out = new BufferedOutputStream(args[1], true);
        } catch(FileNotFoundException e) {
            System.out.println(e);
        } catch(IOException e) {
            System.out.println(e);
        }

        do {
            i=in.read(); // @violation
            s += noLock();
            i++;
        } while(i < 30);

        while(lock() < 1) {
            s += noLock();
        }
    }
}