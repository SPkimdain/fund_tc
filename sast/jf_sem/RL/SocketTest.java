package rl;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * Writer: Gyuhang Shim
 * Resource Leak test case for Socket using
 */
public class SocketTest {
    public void test1() {
        Socket socket = null;
        try {
            socket = new ServerSocket(0).accept();
        } catch (IOException e) {
            System.out.println("IOException");
        }
    }/* BUG */

    public void test2() {
        Socket socket = null;
        try {
            socket = new Socket();
        } catch (Exception e) {
            System.out.println("IOException");
        }
    }/* BUG */

    public void test1_safe() {
        Socket socket = null;
        try {
            socket = new ServerSocket(0).accept();
        } catch (IOException e) {
            System.out.println("IOException");
        } finally {
            if (socket != null) {
                try {
                    socket.close(); /* NOT BUG */
                } catch (IOException e) {

                }
            }
        }
    }

    public void test2_safe() throws IOException {
        Socket socket = null;
        try {
            socket = new Socket();
        } catch (Exception e) {
            System.out.println("IOException");
        } finally {
            if (socket != null) {
                socket.close(); /* NOT BUG */
            }
        }
    }
}
