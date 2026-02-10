public class SecurityIncompleteStaticInitializer {
    class DangerousTrade {
        private static Stock s;
        static {
            try {
                s = new Stock();    // @violation
            } catch (IOException e) {
                /* does not initialize s to a safe state */
            }
        }
        // ...
    }

    class SafeTrade1 {
        private static final Stock s;
        static {
            try {
                s = new Stock();    /* Safe */
            } catch (IOException e) {
                // Do nothing
            }
        }
        // ...
    }

    class SafeTrade2 {
        private static Stock s;
        static {
            try {
                // Do something
            } catch (IOException e) {
                // Do nothing
            } finally {
                s = new Stock();    /* Safe */
            }
        }
        // ...
    }
}