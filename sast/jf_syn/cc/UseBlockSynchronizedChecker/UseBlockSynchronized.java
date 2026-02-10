package method.AvoidSynchronizedAtMethodLevel;

public class UseBlockSynchronized {
    class C{

    }

    public class Bad1{
        class CC{
            public synchronized void bad3(){        // @violation

            }
        }

        synchronized void bad1(){                   // @violation
            C c = new C(){
                public synchronized void bad2(){    // @violation

                }
            };
        }
    }

    public class Good1 {
        class CC {
            public void good3() {
                synchronized (this) { /* compliant */

                }
            }
        }

        void good1() {
            synchronized (this) { /* compliant */
                C c = new C() {
                    public void good2() {
                        synchronized (this) { /* compliant */

                        }
                    }
                };
            }
        }
    }
}