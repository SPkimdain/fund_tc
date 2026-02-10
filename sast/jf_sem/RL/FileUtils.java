package rl;

import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.OutputStream;

/**
 * User: starblood
 * Date: 5/10/13
 * Time: 3:58 PM
 */
public class FileUtils {
    static void close(BufferedInputStream in) {
        if(in != null) {
            try {
                in.close();
            } catch(IOException e) { }
        }
    }
    public static void close(OutputStream out) {
        if (out != null) {
            try {
                out.close();
            } catch (IOException e) {}
        }
    }
}