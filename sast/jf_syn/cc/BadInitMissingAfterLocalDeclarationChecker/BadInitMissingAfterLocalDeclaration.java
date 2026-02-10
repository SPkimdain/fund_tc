package cc;

public class BadInitMissingAfterLocalDeclaration {
    int gVar; /* SAFE since it is a global variable */
    Test gObj; /* SAFE since it is a global variable */
    int[] gArray; /* SAFE since it is a global variable */

    private class Test {}

    public void func(int param) { /* SAFE since it is a parameter */
        int badVar; // @violation
        int goodVar = 0;
        var badVar1; // @violation
        var goodVar1 = 0;

        Test badObj; // @violation
        Test goodObj = new Test();

        int[] badArray; // @violation
        int[] goodArray = new int[]{1, 2, 3};
    }
}
