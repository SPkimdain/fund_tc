package cc;

public class BadWhitespaceAccessing {

    private Inner f;

    private class Inner {
        public int iField;
        public void func(int a) {
            // Do something
        }

        public class GrandInner {
            public int gField;
            public void func(String s) {
                // Do something
            }
        }

        private GrandInner gInner;

        public GrandInner getGInner() {
            return GrandInner;
        }
    }

    public void func() {
        Inner i;
        i.func(0);
        i .func(0); // @violation
        i. func(0); // @violation
        this.f.func(0);
        this .f.func(0); // @violation
        this. f.func(0); // @violation
        this.f .func(0); // @violation
        i/* Comment */.this. /* Comment */func(0); // @violation
        i/* Comment */ .this.func(0); // @violation
        i.getGInner().func("abc . def");
        i.getGInner() .func("abc . def"); // @violation
        i.getGInner()./* Comment */ func("abc . def"); // @violation

        int[] array = {1, 2, 3, 4, 5};
        int[][] arr2d = { {1, 2}, {3, 4} };
        array[0] = 0;
        array/* Comment */ [1] = 1; // @violation
        int j = 1 + array/* Comment */[0] + 2;
        int k = 1 + array [0] + 2; // @violation
        array[0][0] = 0;
        array[0] [1] = 1; // @violation
        array [1][0] = 1; // @violation
        int l = 1 + array[0] [1] + 2; // @violation
        int m = 1 + array [1][0] + 2; // @violation

        i.getGInner()
         .func("abc . def"); // @violation

        i.getGInner(). // @violation
          func("abc . def");
    }
}
