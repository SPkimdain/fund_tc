package src.test.java.pmd;

public class NonThreadSafeSingleton {
    private static NonThreadSafeSingleton foo = null;

    public static NonThreadSafeSingleton getNonThreadSafeSingleton() {
        if (foo==null) { // @violation
            foo = new NonThreadSafeSingleton();
        }
        return foo;
    }

    private static NonThreadSafeSingleton instance = null;

    private NonThreadSafeSingleton() {}

    public static synchronized NonThreadSafeSingleton getInstance() {
        if(instance == null) { /* OK */
            instance = new NonThreadSafeSingleton();
        }
        return instance;
    }
}