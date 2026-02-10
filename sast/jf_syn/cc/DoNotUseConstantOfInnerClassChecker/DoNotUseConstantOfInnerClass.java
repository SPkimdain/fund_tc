package cc;

public class DoNotUseConstantOfInnerClass {

    public static final int currentConstant = 3;

    private class Inner {
        public static final int innerConstant = 5;

        private class GrandInner {
            public static final int grandInnerConstant = 10;
        }

        public GrandInner grandInner;

        public int getGrandInnerConstant() {
            return grandInner.grandInnerConstant; // @violation
        }
    }

    public Inner inner;

    public int func() {
        int x = inner.innerConstant + 5; // @violation
        int y = inner.grandInner.grandInnerConstant + 10; // @violation
        int z = inner.getGrandInnerConstant();
        int q = currentConstant + 10; /* SAFE */
        int w = this.currentConstant + 10; /* SAFE */
        int v = this.inner.innerConstant + 10; // @violation
    }
}
