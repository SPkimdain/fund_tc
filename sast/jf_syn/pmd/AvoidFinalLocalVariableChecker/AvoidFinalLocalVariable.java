package src.test.java.pmd;

public class AvoidFinalLocalVariable {
    final String str1;

    final void sum() {}

    public void fun() {
        final String str2; // @violation
        final String str3 = "FINAL"; // @violation
        final int num = 0; // @violation
        int a = 1;
        final int num2 = a;
    }
}