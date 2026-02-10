package pmd.uselessoverridingmethod;

import src.test.testcase.pmd.uselessoverridingmethod.UselessOverridingMethodParent;

public class UselessOverridingMethod extends UselessOverridingMethodParent {
    void test1() { // @violation
        super.test1();
    }

    String test2() { // @violation
        return super.test2();
    }

    void test3() { /* safe */
       super.test3();
       test1();
       // do something
    }

    class TestCaseClass extends UselessOverridingMethod {
        void test1() { // @violation
            super.test1();
        }

        String test2() { // @violation
            return super.test2();
        }
    }
}