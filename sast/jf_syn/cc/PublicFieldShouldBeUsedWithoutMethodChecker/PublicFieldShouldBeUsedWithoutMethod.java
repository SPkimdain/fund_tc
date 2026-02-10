package cc;

public class PublicFieldShouldBeUsedWithoutMethod {
    private class BadClass {
        public int field; // @violation

        public int getField() {
            return field;
        }
    }

    private class GoodClass {
        public int field;
    }

    private class StaticClass {
        public static int field; /* SAFE since it is a static field */

        public static int getField() {
            return field;
        }
    }
}
