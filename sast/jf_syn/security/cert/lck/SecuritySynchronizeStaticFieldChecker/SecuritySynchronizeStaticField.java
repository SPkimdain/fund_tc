/* This class is not thread-safe */
public final class CountHits {
    private static int counter;
    private static final int constant;
    private int num;

    public void incrementCounter() {
        counter++;                              // @violation
        constant = 2;                           /* Safe */
        num++;                                  /* Safe */
    }
}


/* This class is thread-safe */
public final class CountHits2 {
    private static int counter;
    private static final Object lock = new Object();
    private static int step;

    public void incrementCounter() {
        synchronized (lock) {
            counter++;                          /* Safe */
        }
        step++;                                 // @violation
    }
}