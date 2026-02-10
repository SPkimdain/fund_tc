import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.locks.AbstractQueuedLongSynchronizer.ConditionObject;

public class SecuritySynchronizeLockOrCondition {
    private final Lock lock = new ReentrantLock();
    private final Lock lock_condition = new ConditionObject();

    public void doSomething() {
        synchronized(lock) {            // @violation
            // ...
        }

        synchronized(lock_condition) {            // @violation
            // ...
        }

        lock.lock();                /* Safe */
        try {
            // ...
        } finally {
            lock.unlock();
        }
    }
}
