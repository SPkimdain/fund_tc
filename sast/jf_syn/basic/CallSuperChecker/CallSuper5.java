package test.com.fasoo.javafinch.syn.rule.basic.callsuper;

/**
 * CALL_SUPER Test case 5 : Multi-level inheritance
 * 여러 계층으로 상속이 이루어 질 경우 정상 동작 확인
 * @author JWYoon
 *
 */
public class CallSuper5 {
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

        protected void finalize() { // @violation
            try {
                // Missing super.finalize()
            } catch (Throwable e) {
                e.printStackTrace();
            }

            return;
        }
    }

    class ChildClass extends BaseClass {
        @Override
        protected Object clone() { // Not bug since it is not overriden from Object.clone
            try {
                // Missing super.clone();
            } catch (Throwable e) {
                    e.printStackTrace();
            }

            return null;
        }

        protected void finalize() { // Not bug since it is not overriden from Object.finalize
            try {
                // Missing super.finalize()
            } catch (Throwable e) {
                e.printStackTrace();
            }

            return;
        }
    }
}
