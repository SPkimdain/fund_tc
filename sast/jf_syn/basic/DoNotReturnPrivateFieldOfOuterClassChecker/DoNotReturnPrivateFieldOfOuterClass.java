package basic;

public class DoNotReturnPrivateFieldOfOuterClass {

    private class BadOuter {
        private int privateField;

        private void privateMethod() {
            // Do something ...
        }

        private class Inner {
            private int innerPrivateField;

            private int innerPrivateMethod() {
                BadOuter.this.privateMethod();
                int a = BadOuter.this.privateField;
                return BadOuter.this.privateField; // @violation
            }

            private class GrandInner {
                private int func() {
                    BadOuter.this.privateMethod();
                    int a = BadOuter.this.privateField;

                    int b = Inner.this.innerPrivateMethod();
                    int c = Inner.this.innerPrivateField;
                    return Inner.this.innerPrivateField; // @violation
                }
            }
        }
    }
}