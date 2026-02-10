package basic;

public class DoNotCallRunFinalizersOnExit {

    public void func() {
        System.runFinalizersOnExit(true); // @violation
        java.lang.System.runFinalizersOnExit(true); // @violation
        Runtime.runFinalizersOnExit(true); // @violation
        java.lang.Runtime.runFinalizersOnExit(true); // @violation
    }
}
