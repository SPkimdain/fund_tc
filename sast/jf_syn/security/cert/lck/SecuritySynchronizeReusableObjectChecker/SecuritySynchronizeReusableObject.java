public class SecuritySynchronizeReusableObject {

    private final Boolean initialized = Boolean.FALSE;

    public void doSomething() {
        synchronized (initialized) {            // @violation
            // ...
        }
    }

    int lock = 0;
    private final Integer Lock = lock; // Boxed primitive Lock is shared

    public void doSomething() {
        synchronized (Lock) {                   // @violation
            // ...
        }
    }

    private final String lock = new String("LOCK").intern();

    public void doSomething() {
        synchronized (lock) {                   // @violation
            // ...
        }
    }

    private final String locked = new String("LOCK");     /* Safe */

    public void doSomething() {
        synchronized (locked) {
            // ...
        }
    }


    // This bug was found in jetty-6.1.3 BoundedThreadPool
    private final String lockLiteral = "LOCK";

    public void doSomething() {
        synchronized (lockLiteral) {                        // @violation
            // ...
        }
    }
}