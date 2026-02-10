package cc;

public class BadCurlybraceDeclaration {

    private class BadClass {
        public int a = 0;
        // Do something ...
      } // @violation

    private class BadClass2 { } // @violation

    private class BadClass3
    { // @violation
        public int a = 0;
        // Do something ...
    }

    private class GoodClass {
        public int a = 0;
        // Do something ...
    }

    private class GoodClass2 {}

    public void badFunc() {
        int a = 0;
        // Do something ...
      } // @violation

    public void badFunc2() { } // @violation

    public void badFunc3()
    { // @violation
        int a = 0;
        // Do something ...
    }

    public void goodFunc() {
        int a = 0;
        // Do something ...
    }

    public void goodFunc2() {}
}
