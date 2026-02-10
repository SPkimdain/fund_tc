package basic;

import java.lang.InterruptedException;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class UnreleasedLock {

    private final Lock mutex;
    private int count;

    public UnreleasedLock() {
        this.mutex = new ReentrantLock();
    }

    public void lockTest() {
        this.mutex.lock(); // @violation
    }

    public void unlockTest() {
        this.mutex.unlock();
    }

    public void add(int addOne) throws InterruptedException {
        this.mutex.lock();
        Lock mutexRef = this.mutex;
        mutexRef.unlock();
        count += addOne;

        Lock[] mutexes = new Lock[4];
        mutexes[0].lock(); // mutexes[0] locked
        mutexes[1] = mutexes[0]; // mutexes[1] -> mutexes[0]
        mutexes[2] = mutexes[1]; // mutexes[2] -> mutexes[1] -> mutexes[0]
        mutexes[0] = mutexes[2]; // mutexes[0] -> mutexes[2] -> mutexes[0]
        mutexes[1].lock(); // mutexes[0] locked
        mutexes[1+1].lock(); // mutexes[0] locked
        mutexes[1].unlock(); // mutexes[0] unlocked
        mutexes[3].lock(); // @violation
        mutexes[0] = mutexes[3];
        mutexes[1].unlock(); // mutexes[1] -> mutexes[0] unlocked
    }
}
