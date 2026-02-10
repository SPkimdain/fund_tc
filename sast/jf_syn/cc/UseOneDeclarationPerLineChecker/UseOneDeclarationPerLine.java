package cc;

public class UseOneDeclarationPerLine {
    public int f1;
    public int f2, f3; // @violation

    public void func1() {
        int l1;
        int l2, l3; // @violation
    }

    public void func2() {} public void func3() {} // @violation

    private class inner1 {
    }

    private class inner2 {} private class inner3 {} // @violation

    private class inner4 { public void func4() {} } // @violation

    public void func5() { int l4; } // @violation

    public void func6(int x, int y) {} /* SAFE for parameter declarations */

    Comparator<Integer> lambdaTest1 = () -> {
        int x, y; // @violation
    };

    Comparator<Integer> lambdaTest2 = () -> {
        int x;
        int y;
    };

    Comparator<Integer> lambdaTest3 = () -> { int x; }; // @violation

    Comparator<Integer> lambdaTest4 = () -> {
        int x;
    };
}
