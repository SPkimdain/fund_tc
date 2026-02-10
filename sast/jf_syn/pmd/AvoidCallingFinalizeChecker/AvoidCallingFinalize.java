package pmd;

public class AvoidCallingFinalize {
    public AvoidCallingFinalize() {

    }

    void testCase1() {
        AvoidCallingFinalize avoidCallingFinalize = new AvoidCallingFinalize();

        avoidCallingFinalize.finalize(); // @violation
    }

    class TestClass {
        void testCase2() {
            TestClass testClass = new TestClass();

            testClass.finalize(); // @violation
        }
    }
}