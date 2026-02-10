package basic;

/**
 * Writer: Gyuhang Shim
 * Date: 4/3/12
 */
public class DoNotUseNotify {
    public synchronized void notifyJob() {
        boolean flag = true;
        notify(); // @violation
    }
}
