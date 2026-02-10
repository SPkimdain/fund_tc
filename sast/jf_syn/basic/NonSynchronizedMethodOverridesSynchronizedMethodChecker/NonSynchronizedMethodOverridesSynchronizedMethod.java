package basic;

/**
 * Writer: Gyuhang Shim
 * Date: 4/9/12
 */
public class NonSynchronizedMethodOverridesSynchronizedMethod {
    class U9627 {
        public synchronized void synchronizedMethod() {
            for (int i = 0; i < 10; i++) System.out.println(i);
        }
    }

    class Foo extends U9627 {
        public void synchronizedMethod() { // @violation
            for (int i = 0; i < 10; i++) System.out.println(i);
        }
    }
}
