package test.com.fasoo.javafinch.syn.rule.basic.callsuper;

/**
 * CALL_SUPER Test case 1 : Simple CALL_SUPER
 * 비율에 기반한 기본적인 CALL_SUPER 오류 검출 (비율: 0.65)
 * @author JWYoon
 *
 */
public class CallSuper1 {
    // Code below: A / (A + B) * 100 = 80%
    class BaseClass {
        protected void method() {}
    }

    class ChildA extends BaseClass {
        protected void method() {
            super.method();
        }
    }

    class ChildB extends BaseClass {
        protected void method() {
            super.method();
        }
    }

    class ChildC extends BaseClass {
        protected void method() {
            super.method();
        }
    }

    class ChildD extends BaseClass {
        protected void method() {
            super.method();
        }
    }

    class ChildE extends BaseClass {
        protected void method() {} // @violation
    }

    class BaseClass2 {
        protected void method() {}
    }

    // Code below: A / (A + B) * 100 = 50%
    class ChildF extends BaseClass2 {
        protected void method() {
            super.method();
        }
    }

    class ChildH extends BaseClass2 {
        protected void method() {} // Not bug because of the threshold
    }
}
