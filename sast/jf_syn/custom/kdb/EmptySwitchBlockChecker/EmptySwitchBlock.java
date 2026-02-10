public class EmptySwitchTest {
    public static void main(String[] args) {
        int num = 2;

        switch (num) {
            case 1: //@violation
                break;
            default:
                System.out.println("Invalid case");
                break;
        }
    }
}
