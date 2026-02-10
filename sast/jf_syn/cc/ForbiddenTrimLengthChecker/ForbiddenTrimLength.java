package expression.InefficientEmptyStringCheck;

public class ForbiddenTrimLength {
    class C{
    }

    public class Bad1 {
        class CC {
            void bad1(String string) {
                if (string != null && string.trim().length() > 0) { // @violation
                    //doSomething();
                }
            }
        }

        void bar(String string) {
            if (string != null && string.trim().length() > 0) { // @violation
                //doSomething();

                C c = new C() {
                    void bad2(String string) {
                        if (string != null && string.trim().length() > 0) { // @violation
                            //doSomething();
                        }
                    }
                };
            }
        }
    }

    public class Good1 {

        class CC {
            void good1(String string) {
                if (string != null && hasSpace(string)) { /* compliant */
                    //doSomething();
                }
            }
        }

        void bar(String string) {
            if (string != null && hasSpace(string)) {
                //doSomething();

                C c = new C() {
                    void bad2(String string) {
                        if (string != null && hasSpace(string)) { /* compliant */
                            //doSomething();
                        }
                    }
                };
            }
        }
    }
}