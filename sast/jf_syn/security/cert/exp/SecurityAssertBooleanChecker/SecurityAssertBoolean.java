public class SecurityAssertBoolean {

    private ArrayList<String> names;

    void process(int index) {
        assert names.remove(null);      // @violation
        assert index++;                 // @violation
        assert index = 2;               // @violation
        assert ++index;                 // @violation
        assert names.remove(index++);   // @violation
        // ...
    }

    void proces2(int index) {
        boolean nullsRemoved = names.remove(null);
        assert nullsRemoved;            /* Safe */
        // ...
    }
}