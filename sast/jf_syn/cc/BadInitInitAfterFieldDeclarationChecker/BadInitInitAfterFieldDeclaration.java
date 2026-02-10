package cc;

public class BadInitInitAfterFieldDeclaration {
    private class Test {}

    private int badVar = 0; // @violation
    private int goodVar;

    private Test badObj = new Test(); // @violation
    private Test goodObj;

    private int[] badArray = new int[]{1, 2, 3}; // @violation
    private int[] goodArray;

    public void func(int param) { /* SAFE since it is a parameter */
        int goodVar = 0; /* SAFE since it is a local variable */
        Test goodObj = new Test(); /* SAFE since it is a local variable */
        int[] goodArray = new int[]{1, 2, 3}; /* SAFE since it is a local variable */
    }
}
