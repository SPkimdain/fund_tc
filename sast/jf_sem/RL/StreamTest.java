package rl;

import java.io.*;

public class StreamTest {
    public BufferedInputStream getInputStream() {
        String pass = null;
        int x = 10;
        int i = 0;
        BufferedInputStream is = null;
        try {
            is = new BufferedInputStream(new FileInputStream(new File("")));
        } catch (IOException e) {
            System.out.println("error!");
        }
        return is;
    }
    public void simpleTest() {
        BufferedInputStream i = getInputStream();
        System.out.println("nothing.");
    } /* BUG */
    public void exceptionTest() {
        BufferedInputStream is = null;
        int x = 0;
        int y = 0;
        try {
            y = System.in.read();
        } catch (IOException e) {
            y = 1;
        }
        try {
            is = new BufferedInputStream(new FileInputStream(new File("")));
            x = 1;
            x = 2;
            if(y > 0) throw new IOException();
            x = 3;
        } catch (IOException e) {
            x = 4;
        } finally {
            try {
                is.close();
            } catch(IOException e) {}
        }
        System.out.println(x);
    }
 }