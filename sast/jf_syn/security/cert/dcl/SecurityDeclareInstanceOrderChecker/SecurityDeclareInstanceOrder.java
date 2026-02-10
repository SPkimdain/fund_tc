public class Cycle {
    private final int balance;
    private static final Cycle c = new Cycle(); // @violation
    private static final int deposit = (int) (Math.random() * 100);

    public Cycle() {
        balance = deposit - 10; // Subtract processing fee
    }

    public static void main(String[] args) {
        System.out.println("The account balance is: " + c.balance);
    }
}