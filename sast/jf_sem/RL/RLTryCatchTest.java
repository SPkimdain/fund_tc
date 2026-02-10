package rl;

import java.io.*;
import java.nio.channels.FileChannel;

/**
 * Writer: Gyuhang Shim
 * Date: 7/2/12
 */
public class RLTryCatchTest {
    public void test1() {
        File file = new File("tmp");
        try {
            BufferedReader br = new BufferedReader(new FileReader(file));
            br.readLine();// might throw IOException // 분석기 semantics 에 Exception 을 throw 할 수 있다는 정보가 있음
            br.close();
        } catch (Exception e) {
            System.out.println("haha");
        }
    } /* BUG */ // Resource Leak

    public void safe1() {
        File file = new File("tmp");
        BufferedReader br = null;
        try {
            br = new BufferedReader(new FileReader(file));
            br.readLine();
        } catch (Exception e) {
            System.out.println("haha");
        } finally {
            if (br != null) {
                try {
                    br.close();
                } catch (IOException e) {}
            }
        }
    } /* NOT BUG */

    public void safe2() throws IOException {
        File file = new File("tmp");
        DataInputStream in = null;
        try {
            in= new DataInputStream(new BufferedInputStream(new FileInputStream(file)));
            int version = in.readInt();
        } catch (IOException e) {
           throw new IOException("error");
        } finally {
            if (in != null) {
                try {in.close();} catch(IOException ioe) {}
            }
        }
    } /* NOT BUG */

    public void safe3() throws IOException {
        RandomAccessFile file = new RandomAccessFile("tmp","rw");
        FileChannel out = file.getChannel();
        try {
            long size = out.size();
            System.out.println(size);
        } catch (IOException e) {
            throw new IOException("error");
        } finally {
            if (out != null) {
                try {out.close();} catch(IOException ioe) {}
            }
        }
    } /* NOT BUG */
}
