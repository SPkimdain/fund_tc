package cc;

public interface MissingClassInSourceFile1 {    // @violation
    private class TestClass {
        public class Test2{

        }

    }
}