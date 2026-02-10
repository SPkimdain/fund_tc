public class UnnecessaryStatementTest {
    public static void main(String[] args) {

        ; //@violation

        System.out.println("Hello");; //@violation


        System.out.println("Valid statement");
    }
}
