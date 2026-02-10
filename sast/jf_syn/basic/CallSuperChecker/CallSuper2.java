package test.com.fasoo.javafinch.syn.rule.basic.callsuper;

/**
 * CALL_SUPER Test case 2 : Override Object.clone
 * Object.clone()을 오버라이드 하는 경우 비율과 상관없이 검출
 * @author JWYoon
 *
 */
public class CallSuper2 {
    class BaseClass {
        @Override
        protected Object clone() { // @violation
            try {
                // Missing super.clone();
            } catch (Throwable e) {
                    e.printStackTrace();
            }

            return null;
        }
    }

    class BaseClass2 {
        @Override
        protected Object clone() {
            try {
                super.clone();
            } catch (Throwable e) {
                    e.printStackTrace();
            }

            return null;
        }
    }
}
