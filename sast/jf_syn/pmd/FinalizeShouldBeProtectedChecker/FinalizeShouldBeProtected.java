package src.test.java.pmd;

public class FinalizeShouldBeProtected {

    class A {
        protected void finalize() { /* OK */
            // do something
        }
    }

    public void finalize() { // @violation
        // do something
    }

}