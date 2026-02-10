package cc;

public class DoNotUseSynchronizedStatement {
    public synchronized void synFunc() {
        // Do something ...
    }

    public void nonSynFunc() {
        synchronized (this) { // @violation
            // Do something ...
        }
    }
}
