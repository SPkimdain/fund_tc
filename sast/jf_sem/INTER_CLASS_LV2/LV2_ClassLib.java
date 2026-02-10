package inter_class_lv2;

/* inter class level 2 test */
public class LV2_ClassLib {
    public static String getString() {
        LV2_ClassA clazzA = new LV2_ClassA();
        LV2_ClassB clazzB = new LV2_ClassB();

        int a = -1;
        int b = -2;
        int c = -1;

        if (LV2_CLASS.getOddInt(a + b) < 0) { // -1 < 0
            a = clazzA.getSomeInt(); // 1
            b = clazzB.getSomeInt(); // 3
            c = a + b;
        }

        String str = null;
        if (c > 0) { // (c = 4) > 0
            str = "abc";
        }
        return str; // returns "abc"
    }

    public static String getNullString() {
        LV2_ClassA clazzA = new LV2_ClassA();
        return clazzA.getNullString();
    }
}
