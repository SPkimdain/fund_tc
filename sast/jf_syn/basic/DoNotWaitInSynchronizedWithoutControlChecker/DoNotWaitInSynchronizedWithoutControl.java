package basic;

import java.util.concurrent.locks.Lock;

public class DoNotWaitInSynchronizedWithoutControl {

    public void badWait() {
        Lock lock;
        boolean condition;
        // Do something ...

        synchronized(lock) {
            lock.wait(); // @violation
        }

        while(condition) {
            synchronized (lock) {
                lock.wait(); // @violation
            }
        }
    }

    public void goodWait(int k) {
        Lock lock;
        boolean condition;
        // Do something ...

        synchronized(lock) {
            if(condition) {
                lock.wait(); /* SAFE */
                // Do something ...
            }

            if(!condition) {
                // Do something ...
            } else {
                lock.wait(); /* SAFE */
            }

            while(condition) {
                lock.wait(); /* SAFE */
                // Do something ...
            }

            for(int i=0; i<10; i++) {
                lock.wait(); /* SAFE */
                // Do something ...
            }

            do {
                lock.wait(); /* SAFE */
                // Do something ...
            } while(condition);

            switch (k) {
            case 0:
                lock.wait(); /* SAFE */
                break;
                // Do something ...
            default:
                break;
            }
        }
    }

}