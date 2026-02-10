package cc;

public class BadCurlyBraceGeneral {
    public enum EnumTest {
        A, B, C
    }

    private class ClassTest {
        // constructor
        public ClassTest() {

        }

        private static ClassTest singleInstance;

        static { // test line comment // @violation
            singleInstance = new ClassTest();
        }

        static { /* test block comment */ // @violation
            singleInstance = new ClassTest();
        }


        @SuppressWarnings({"a", "b", "c"})
        public void decledMethod(int x, int y)
 /* @violation */ {
            int a[] = {4, 5, 6};

            int b[] = {7, 8, 9};

            switch (x) {
                case 0:
                    // if-else
                    if (x == y) {

                    } else {} // emtpy block // @violation 2
                    break;
                case 1:
                    // single if
                    if (y < x) {
                    badCode(); } // @violation
                    if (y > x) return; // non block
                    break;
                case 2:
                    // foreach
                    for (String x: new String[]{"a", "b", "c"}) {
                        // for with tail space
                        for (int i = 1; i < 10; i++) {

                        /* comment */} // @violation
                    }
                    break;
                case 3:
                { // normal block
                    synchronized (a)
   /* @violation */ {
                        // test sync
                    }
                /* close~ */}
                default:
                    break;
            }
        }
    }

    private @interface MyAnnot {

    }

    protected interface InterfaceTest {
        public void emptyMethod();
    }
}