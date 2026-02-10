// Thread-safe class
public final class SocketReader implements Runnable {
    private final Socket socket;
    private final BufferedReader in;
    private volatile boolean done = false;
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
            synchronized (lock) {
                readData();
            }
        } catch (IOException ie) {
            // Forward to handler
        }
    }

    public void readData() throws IOException {
        String string;
        while (!done && (string = in.readLine()) != null) {                     // @violation
            // Blocks until end of stream (null)
        }

        while (!Thread.interrupted() && (string = in.readLine()) != null) {     // @violation
            // Blocks until end of stream (null)
        }

        synchronized (lock) {
            while (!Thread.interrupted() && (string = in.readLine()) != null) {     /* Safe */
                // ...
            }
        }

        try {
            while ((string = in.readLine()) != null) {                          /* Safe */
                // Blocks until end of stream (null)
            }
        } finally {
            shutdown();
        }
    }

    public void shutdown() {
        done = true;
    }

    public static void main(String[] args)
            throws IOException, InterruptedException {
        SocketReader reader = new SocketReader("somehost", 25);
        Thread thread = new Thread(reader);
        thread.start();
        Thread.sleep(1000);
        reader.shutdown(); // Shutdown the thread
    }
}