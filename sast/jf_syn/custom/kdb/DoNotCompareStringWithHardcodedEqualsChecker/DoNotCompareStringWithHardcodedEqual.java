public class HardcodedEqualsTest {

    public static void main(String[] args) {

        String input = "abc";
        if (input.equals("sparrow")) { //@violation
            System.out.println("Equals match!");
        }

        if (input.equalsIgnoreCase("SPARROW")) { //@violation
            System.out.println("EqualsIgnoreCase match!");
        }

        if ("sparrow".equals(input)) { //@safe
            System.out.println("Safe equals usage");
        }
    }
}
