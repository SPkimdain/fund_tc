package custom;

public class DoNotUseThreadInheritance {
    public class Violation1 extends Thread {                // @violation
        @Override
        public void run() {
            super.run();
            // ...
        }
    }

    public class Violation2 extends java.lang.Thread {      // @violation
        @Override
        public void run() {
            super.run();
            // ...
        }
    }

    public class Good implements Runnable {                 /* SAFE */
        @Override
        public void run() {
            // ...
        }
    }
}
