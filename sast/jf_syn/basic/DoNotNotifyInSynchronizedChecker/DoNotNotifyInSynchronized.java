package basic;

public class DoNotNotifyInSynchronized {

    public void good() {
        // Do something ...
        notify();
        // Do something ...
    }

    public synchronized void badM() {
        // Do something ...
        notify(); // @violation
        // Do something ...
    }

    public void badB() {
        // Do something ...
        synchronized (this) {
            notify(); // @violation
        }
        // Do something ...
    }
}