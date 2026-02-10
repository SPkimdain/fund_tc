package cc;

public class DoNotAccessPrivateMemberOfOuterClass {

    private class BadOuter {
        private int privateField;

        private void privateMethod() {
            // Do something ...
        }

        private class Inner {
            private int innerPrivateField;

            private void innerPrivateMethod() {
                BadOuter.this.privateMethod(); // @violation
                int a = BadOuter.this.privateField; // @violation
            }

            private class GrandInner {
                private void func() {
                    BadOuter.this.privateMethod(); // @violation
                    int a = BadOuter.this.privateField; // @violation

                    Inner.this.innerPrivateMethod(); // @violation
                    int b = Inner.this.innerPrivateField; // @violation
                }
            }
        }
    }

    private class GoodOuter {
        protected int privateField;

        protected void privateMethod() {
            // Do something ...
        }

        private class Inner {
            protected int innerPrivateField;

            protected void innerPrivateMethod() {
                GoodOuter.this.privateMethod();
                int a = GoodOuter.this.privateField;
            }

            private class GrandInner {
                private void func() {
                    GoodOuter.this.privateMethod();
                    int a = GoodOuter.this.privateField;

                    Inner.this.innerPrivateMethod();
                    int b = Inner.this.innerPrivateField;
                }
            }
        }
    }
}