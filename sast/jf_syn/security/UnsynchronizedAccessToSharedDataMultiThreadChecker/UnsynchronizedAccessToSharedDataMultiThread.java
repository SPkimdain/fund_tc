package security;

public final class CountHits {

    private static int counter;
    private static final int constant;
    private int num;

    public void incrementCounter() {
        counter++;                              // @violation
        constant = 2;                           /* Safe */
        num++;                                  /* Safe */

        Thread thread = new Thread(this);
        thread.start();                         // @violation

    }
}
