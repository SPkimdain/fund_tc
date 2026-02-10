package cc;

public class DoNotLockOrUnlockInLoop {

    /** Method that is not synchronized */
    public int unLock() {
        // Do something ...
        return 1;
    }

    /** Method that is synchronized */
    public synchronized int lock() {
        // Do something ...
        return 1;
    }

    /** Method that is synchronized */
    private int noLock() {
        // Do something ...
        return 1;
    }

    public void func() {
        int i, s=0;
        for(i=0; i<10; i++) {
            s += unLock(); // @violation
            s += lock(); // @violation
            s += noLock();
        }

        while(i < 20) {
            s += unLock(); // @violation
            s += lock(); // @violation
            s += noLock();
            i++;
        }

        do {
            s += unLock(); // @violation
            s += lock(); // @violation
            s += noLock();
            i++;
        } while(i < 30);

        while(lock() < 1) {
            s += noLock();
        }
    }
}
