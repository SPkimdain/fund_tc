public class AssignmentInOperandTest {
    public static void main(String[] args) {

        if ((x = getX()) == 3) {} //@violation

        while ((y += 2) < 10) {} //@violation

        for (int i = 0; (i = getVal()) < 5; i++) {} //@violation

        if ((x = getX()) == 3) {}  //@violation

        while ((y += 2) < 10) {}  //@violation
    }
}
