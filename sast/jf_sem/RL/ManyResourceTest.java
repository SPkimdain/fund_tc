package rl;

import javax.management.Query;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

class ManyResourceTest{
    public void test1_safe(
            ServerSocket ss1,
            ServerSocket ss2,
            ServerSocket ss3,
            ServerSocket ss4,
            ServerSocket ss5,
            ServerSocket ss6
                           ) {
        Socket socket1 = null;
        Socket socket2 = null;
        Socket socket3 = null;
        Socket socket4 = null;
        Socket socket5 = null;
        Socket socket6 = null;
        try {
            socket1 = ss1.accept();
            socket2 = ss2.accept();
            socket3 = ss3.accept();
            socket4 = ss4.accept();
            socket5 = ss5.accept();
            socket6 = ss6.accept();
        } catch (IOException e) {
            System.out.println("IOException");
        } finally {
            if (socket1 != null) {try {socket1.close(); /* NOT BUG */} catch (IOException e) {}}
            if (socket2 != null) {try {socket2.close(); /* NOT BUG */} catch (IOException e) {}}
            if (socket3 != null) {try {socket3.close(); /* NOT BUG */} catch (IOException e) {}}
            if (socket4 != null) {try {socket4.close(); /* NOT BUG */} catch (IOException e) {}}
            if (socket5 != null) {try {socket5.close(); /* NOT BUG */} catch (IOException e) {}}
            if (socket6 != null) {try {socket6.close(); /* NOT BUG */} catch (IOException e) {}}
        }
    }
    public void foo (){
        try {
            test1_safe(
                    new ServerSocket(0),
                    new ServerSocket(0),
                    new ServerSocket(0),
                    new ServerSocket(0),
                    new ServerSocket(0),
                    new ServerSocket(0)
            );
        }
        catch (IOException e) {
            System.out.println("IOException");
        }
        finally {}
    }
}



