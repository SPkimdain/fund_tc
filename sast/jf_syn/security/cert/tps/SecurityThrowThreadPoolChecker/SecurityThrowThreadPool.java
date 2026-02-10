final class PoolService {
    private static final ThreadFactory factory =
            new ExceptionThreadFactory(new MyExceptionHandler());
    private final ExecutorService pool_factory = Executors.newFixedThreadPool(10, factory); /* Safe */
    private final ExecutorService pool = Executors.newFixedThreadPool(10); // @violation

    public void doSomething() {
        pool_factory.execute(new Task());
        pool.execute(new Task2());
    }

    public static class ExceptionThreadFactory implements ThreadFactory  {
        private static final ThreadFactory defaultFactory =
                Executors.defaultThreadFactory();
        private final Thread.UncaughtExceptionHandler handler;

        public ExceptionThreadFactory(
                Thread.UncaughtExceptionHandler handler)
        {
            this.handler = handler;
        }

        @Override public Thread newThread(Runnable run) {
            Thread thread = defaultFactory.newThread(run);
            thread.setUncaughtExceptionHandler(handler);
            return thread;
        }
    }

    public static class MyExceptionHandler extends ExceptionReporter
            implements Thread.UncaughtExceptionHandler {
        // ...

        @Override public void uncaughtException(Thread thread, Throwable t) {
            // Recovery or logging code
        }
    }
}

final class Task implements Runnable {
    @Override public void run() {
        // ...
        throw new NullPointerException();
        // ...
    }
}

final class Task2 implements Runnable {
    @Override public void run() {
        // ...
        throw new NullPointerException();
        // ...
    }
}