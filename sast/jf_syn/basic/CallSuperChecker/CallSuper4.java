package test.com.fasoo.javafinch.syn.rule.basic.callsuper;

/**
 * CALL_SUPER Test case 4 : White list
 * White list 인식 여부 확인(test.com.fasoo.javafinch.syn.rule.basic.callsuper.CallSuper4.BaseClass.method())
 * @author JWYoon
 *
 */
public class CallSuper4 {
    class BaseClass {
        // test.com.fasoo.javafinch.syn.rule.basic.callsuper.CallSuper4.BaseClass.method() is added into the white list
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
        protected void method() {} // Ignored because of the white list
    }
}
