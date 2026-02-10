public final class ConnectionFactory {
    private static Connection dbConnection;
    // Other fields ...

    static {
        Thread dbInitializerThread = new Thread(new Runnable() {            // @violation
            @Override public void run() {
                // Initialize the database connection
                try {
                    dbConnection = DriverManager.getConnection("connection string");
                } catch (SQLException e) {
                    dbConnection = null;
                }
            }
        });

        // Other initialization, for example, start other threads

        dbInitializerThread.start();
        try {
            dbInitializerThread.join();
        } catch (InterruptedException ie) {
            throw new AssertionError(ie);
        }
    }

    public static Connection getConnection() {
        if (dbConnection == null) {
            throw new IllegalStateException("Error initializing connection");
        }
        return dbConnection;
    }

    private static final ThreadLocal<Connection> connectionHolder
            = new ThreadLocal<Connection>() {
        @Override public Connection initialValue() {
            try {
                Connection dbConnection =
                        DriverManager.getConnection("connection string");
                return dbConnection;
            } catch (SQLException e) {
                return null;
            }
        }
    };

    public static void main(String[] args) {
        // ...
        Connection connection = getConnection();
    }
}