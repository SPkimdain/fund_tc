package src.test.java.pmd;

public class DoNotCallThreadRun extends Thread {
    void fun() {
        DoNotCallThreadRun t = new DoNotCallThreadRun();
        Thread th = new Thread();

        t.run(); // @violation
        t.start();
        th.run(); // @violation

        new DoNotCallThreadRun().run(); // @violation
        new Thread().run(); // @violation
    }
}