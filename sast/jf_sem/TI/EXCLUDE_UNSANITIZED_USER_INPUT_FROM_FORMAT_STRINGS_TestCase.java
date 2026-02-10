package ti;

import java.util.GregorianCalendar;
import java.util.Calendar;

class EXCLUDE_UNSANITIZED_USER_INPUT_FROM_FORMAT_STRINGS_TestCase {
    static Calendar c =
            new GregorianCalendar(1995, GregorianCalendar.MAY, 23);

    public static void print(String s) {
        System.out.printf(s + " did not match! HINT: It was issued on %1$terd of some month", c);
    }

    public static void printSafe(String s) {
        System.out.printf("%s did not match! " + " HINT: It was issued on %1$terd of some month", s, c);
    }

    public static void main(String[] args) {
        // args[0] is the credit card expiration date
        // args[0] can contain either %1$tm, %1$te or %1$tY as malicious
        // arguments
        // First argument prints 05 (May), second prints 23 (day)
        // and third prints 1995 (year)
        // Perform comparison with c, if it doesn't match print the
        // following line
        printSafe(args[0]);
        print(args[0]); /* BUG */

    }
}