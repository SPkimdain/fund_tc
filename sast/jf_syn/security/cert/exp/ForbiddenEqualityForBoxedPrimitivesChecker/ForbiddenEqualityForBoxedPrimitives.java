import java.util.Comparator;

public class ForbiddenEqualityForBoxedPrimitives {
    public static void main(String[] args) {
        Integer i1 = 100;
        Integer i2 = 100;
        Integer i3 = 1000;
        Integer i4 = 1000;
        System.out.println(i1 == i2);   // @violation
        System.out.println(i1 != i2);   // @violation
        System.out.println(i3 == i4);   // @violation
        System.out.println(i3 != i4);   // @violation

        ArrayList<Integer> list1 = new ArrayList<Integer>();
        for (int i = 0; i < 10; i++) {
            list1.add(i + 1000);
        }

        ArrayList<Integer> list2 = new ArrayList<Integer>();
        for (int i = 0; i < 10; i++) {
            list2.add(i + 1000);
        }

        int counter = 0;
        for (int i = 0; i < 10; i++) {
            if (list1.get(i) == list2.get(i)) {  // @violation
                counter++;
            }
        }

        Boolean b1 = new Boolean("true");
        Boolean b2 = new Boolean("true");
        Boolean b3 = true;
        Boolean b4 = true;

        if (b1 == b2) {    // @violation
            System.out.println("Never printed");
        }
        if (b3 == b4) {    /* SAFE */
            System.out.println("Never printed");
        }

    }
}