package pmd;

public class SignatureDeclareThrowsException {
    public SignatureDeclareThrowsException() throws Exception { // @violation

    }

    public void testCase1() throws Exception { // @violation

    }

    class TestCase2 {
        public TestCase2() throws Exception { // @violation

        }

        public void testCase3() throws Exception { // @violation

        }
    }
}