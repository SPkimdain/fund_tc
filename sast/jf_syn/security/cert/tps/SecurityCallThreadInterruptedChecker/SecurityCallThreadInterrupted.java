public final class SocketReader implements Runnable { // Thread-safe class
    private final Socket socket;
    private final BufferedReader in;
    private final Object lock = new Object();

    public SocketReader(String host, int port) throws IOException {
        this.socket = new Socket(host, port);
        this.in = new BufferedReader(
                new InputStreamReader(this.socket.getInputStream())
        );
    }

    // Only one thread can use the socket at a particular time
    @Override public void run() {
        try {
            synchronized (lock) {                                        // @violation
                readData();
            }
        } catch (IOException ie) {
            // Forward to handler
        }
    }

    public void readData() throws IOException {
        String string;
        try {
            while ((string = in.readLine()) != null) {
                // Blocks until end of stream (null)
            }
        } finally {
            shutdown();
        }
    }

    public void shutdown() throws IOException {
        socket.close();
    }
}


public final class SocketReader2 implements Runnable {
    private final SocketChannel sc;
    private final Object lock = new Object();

    public SocketReader(String host, int port) throws IOException {
        sc = SocketChannel.open(new InetSocketAddress(host, port));
    }

    @Override public void run() {
        ByteBuffer buf = ByteBuffer.allocate(1024);
        try {
            synchronized (lock) {                                       /* Safe */
                while (!Thread.interrupted()) {
                    sc.read(buf);
                    // ...
                }
            }
        } catch (IOException ie) {
            // Forward to handler
        }
    }
}