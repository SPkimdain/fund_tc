public class SecuritySynchronizeAtomicValue {
    private boolean flag = true;
    private boolean flag2 = true;

    public void toggle() {  // Unsafe
        flag ^= true;  // Same as flag = !flag;
    }

    public boolean getFlag() { // @violation
        return flag;
    }

    public synchronized void toggle2() {  // Safe
        flag2 ^= true;  // Same as flag = !flag;
    }

    public synchronized boolean getFlag2() { // Safe
        return flag2;
    }
}
