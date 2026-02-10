public class FordiddenCallPublicMethod {

    private void readObject(final ObjectInputStream stream)
            throws IOException, ClassNotFoundException {
        AnotherClass anotherClass = new AnotherClass();
        String a;

        overridableMethod();                            // @violation

        nonOverridableMethod();                         /* Safe */

        anotherClass.overridableMethodInAnotherClass(); // @violation

        nonOverridableMethod(a);                        /* Safe */

        stream.defaultReadObject();

        anotherClass.overridableMethodInAnotherClass(); /* Safe */
    }

    public void overridableMethod() {
        // ...
    }

    public final void nonOverridableMethod() {
        // ...
    }

    private void nonOverridableMethod(String a) {
        // ...
    }
}

public class AnotherClass {
    public void overridableMethodInAnotherClass() {
        // ...
    }
}