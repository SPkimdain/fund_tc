package cc;

public class DoNotCallSynchronizedMethodInLoop {

    /** Method that is not synchronized */
    public int unSync() {
        // Do something ...
        return 1;
    }

    /** Method that is synchronized */
    public synchronized int sync() {
        // Do something ...
        return 1;
    }

    public void func() {
        int i, s=0;
        for(i=0; i<10; i++) {
            s += unSync();
            s += sync(); // @violation
        }

        while(i < 20) {
            s += unSync();
            s += sync(); // @violation
            i++;
        }

        do {
            s += unSync();
            s += sync(); // @violation
            i++;
        } while(i < 30);

        while(sync() < 1) {
            s += unSync();
        }
    }
}
