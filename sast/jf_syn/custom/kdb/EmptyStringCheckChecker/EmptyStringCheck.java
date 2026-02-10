public class ToStringExample {
    public static void main(String[] args) {
        String s = "Hello";

        String result = s.toString();
        check(result);
        if (result != null && result.trim().length() == 0) { //@violation
            System.out.println(result);
        }
    }
}
