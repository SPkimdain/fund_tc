package basic;

public class UseStrictfpForDivision {

    private class NonStrictfpClass {
        private void badFunc(int a, int b) {
            a = b / 2; // @violation
        }

        private strictfp void goodFunc(int a, int b) {
            a = b / 2;
        }
    }

    private strictfp class NonStrictfpClass {
        private void badFunc(int a, int b) {
            a = b / 2;
        }

        private strictfp void goodFunc(int a, int b) {
            a = b / 2;
        }
    }
}