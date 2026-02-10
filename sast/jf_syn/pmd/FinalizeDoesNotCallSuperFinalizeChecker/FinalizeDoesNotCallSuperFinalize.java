package pmd;

public class FinalizeDoesNotCallSuperFinalize {
    class TestCase1 {
        protected void finalize() { /* safe */
            super.finalize();
        }
    }

    class TestCase2 {
        protected void finalize() { // @violation
            something();
            // super.finalize();
        }
    }

    class TestCase3 {
        protected void finalize() { // @violation
            super.finalize();
            something();
        }
    }

    class TestCase4 {
        protected void finalize() { /* safe */
            something();
            super.finalize();
        }
    }

    void testCase5() {
        try {
            // do something
        } finally { // @violation
            something();
        }
    }
}