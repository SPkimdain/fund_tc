
class Helper {
    public void handle(Socket socket) {
        //...
    }
}

final class RequestHandler {
    private final Helper helper = new Helper();
    private final ServerSocket server;

    private RequestHandler(int port) throws IOException {       // @violation
        server = new ServerSocket(port);
    }

    public static RequestHandler newInstance() throws IOException {
        return new RequestHandler(0); // Selects next available port
    }

    public void handleRequest() {
        new Thread(new Runnable() {
            public void run() {
                try {
                    helper.handle(server.accept());
                } catch (IOException e) {
                    // Forward to handler
                }
            }
        }).start();
    }

}