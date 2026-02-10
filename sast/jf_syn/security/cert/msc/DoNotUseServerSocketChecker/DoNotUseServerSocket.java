package cert;

import java.net.ServerSocket;
import java.net.Socket;
// Exception handling has been omitted for the sake of brevity
class DoNotUseServerSocket {
    public static void main(String[] args) throws IOException {
        ServerSocket serverSocket = null;   // @violation
        try {
            serverSocket = new ServerSocket(9999);
            Socket socket = serverSocket.accept();   // @violation
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader in = new BufferedReader(
                    new InputStreamReader(socket.getInputStream()));
            String inputLine;
            while ((inputLine = in.readLine()) != null) {
                System.out.println(inputLine);
                out.println(inputLine);
            }
        } finally {
            if (serverSocket != null) {
                try {
                    serverSocket.close();
                } catch (IOException x) {
                    // Handle error
                }
            }
        }
    }
}