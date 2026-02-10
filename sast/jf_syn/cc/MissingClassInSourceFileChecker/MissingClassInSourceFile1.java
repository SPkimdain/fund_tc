package cc;

private interface MissingClassInSourceFile1 {    // @violation
    private class TestClass { // @violation
        public class Test2{

        }

    }
}

private class MissingClassInSourceFile2 { // @violation 2

}