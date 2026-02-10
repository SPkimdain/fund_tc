package io;
final class SecurityCallThreadStart implements Runnable {
    public ThreadStarter() {
        Thread thread = new Thread(this);
        thread.start();                         // @violation
    }

    @Override public void run() {
        // ...
    }

    public void runThreadGood() {
        Thread thread = new Thread(this);
        thread.start();                         /* Safe */
    }
}