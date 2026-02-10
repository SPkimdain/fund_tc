package test.com.fasoo.javafinch.syn.rule.basic.callsuper;

/**
 * CALL_SUPER Test case 3 : Override Object.finalize
 * Object.finalize()를 오버라이드 하는 경우 비율과 상관없이 검출
 * @author JWYoon
 *
 */
public class CallSuper3 {
    class BaseClass {
        protected void finalize() { // @violation
            try {
                // Missing super.finalize()
            } catch (Throwable e) {
                e.printStackTrace();
            }

            return;
        }
    }

    class BaseClass2 {
        protected void finalize() {
            try {
                super.finalize();
            } catch (Throwable e) {
                e.printStackTrace();
            }

            return;
        }
    }
}
