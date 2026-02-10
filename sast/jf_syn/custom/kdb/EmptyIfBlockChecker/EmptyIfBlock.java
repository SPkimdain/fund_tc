public class EmptyIfBlock {

    public static void main(String[] args) {
        boolean condition = true;
        boolean test = false;

        if (condition) {} //@violation

        else if (!condition) { } //@violation

        else { } //@violation
    }
}
