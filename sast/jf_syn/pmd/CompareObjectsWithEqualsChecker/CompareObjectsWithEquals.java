package pmd;

public class CompareObjectsWithEquals {
    public String str1 = "test";
    public String str2 = "test";

    public Test testClass = new Test();

    String strMethod1() {
        return "test";
    }

    String strMethod2() {
        return "test";
    }

    void testCase1() {
        if(this.str1 == this.str2) { // @violation

        }
    }

    void testCase2() {
        if(this.strMethod1() == this.strMethod2()) { // @violation

        }
    }

    void testCase3() {
        if(this.str1.equals(this.str2)) { /* safe */

        }
    }

    void testCase4() {
        if(Test.test1 == Test.test2) { // @violation

        }
    }

    void testCase5() {
        if(testClass.test3 != testClass.test4) { /* safe */

        }
    }

    void testCase6() {
        if(testClass.boolMethod1() == testClass.boolMethod2()) { /* safe */

        }
    }

    void testCase7() {
        if(this.str1 == null) { /* safe */

        }
    }

    class Test {
        private String test1 = "test";
        private String test2 = "test";
        public boolean test3 = true;
        public boolean test4 = true;

        boolean boolMethod1() {
            return true;
        }

        boolean boolMethod2() {
            return true;
        }
    }
}