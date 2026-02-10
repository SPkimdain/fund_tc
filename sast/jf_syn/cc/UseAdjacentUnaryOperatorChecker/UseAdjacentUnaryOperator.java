package cc;

public class UseAdjacentUnaryOperator {
    public void func(int var) {
        var++;
        var--;
        var ++; // @violation
        var     --; // @violation

        ++var;
        --var;
        ++ var; // @violation
        --      var; // @violation
    }

    Comparator<Integer> lambdaTest1 = (int var) -> var++;
    Comparator<Integer> lambdaTest2 = (int var) -> var ++; // @violation
    Comparator<Integer> lambdaTest3 = (int var) -> var  ++; // @violation
    Comparator<Integer> lambdaTest4 = (int var) -> ++var;
    Comparator<Integer> lambdaTest5 = (int var) -> ++ var; // @violation
    Comparator<Integer> lambdaTest5 = (int var) -> ++   var; // @violation
}
