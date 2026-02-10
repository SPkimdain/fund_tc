package cc;

public class TooLongColumn {
    public int methodWithTheLongNameToTestChecker(int a, int b) {
        return a+b;
    }

    public void func() {
        int thisIsALongVariableToTestChecker = 1;
        int anotherLongVariableToTestChecker = 2;
        boolean aLongNamedBooleanVariableToTestChecker;

        aLongNamedBooleanVariableToTestChecker = (thisIsALongVariableToTestChecker + anotherLongVariableToTestChecker) == 3; // @violation

        aLongNamedBooleanVariableToTestChecker = true; /* @violation: A long comment and the alarm will be generated if the comment is not ignored */
        aLongNamedBooleanVariableToTestChecker = /* @violation: Even though the comment is ignored, it is still bug because of the trailing expression */ true;

        methodWithTheLongNameToTestChecker(thisIsALongVariableToTestChecker,
                                           anotherLongVariableToTestChecker * thisIsALongVariableToTestChecker + anotherLongVariableToTestChecker); // @violation
        methodWithTheLongNameToTestChecker(thisIsALongVariableToTestChecker, /* BUG: If only the comment is not ignored // @violation
                                                                              * BUG: If only the comment is not ignored // @violation
                                                                              * BUG: If only the comment is not ignored */ // @violation
                                           anotherLongVariableToTestChecker * /* BUG: If only the comment is not ignored // @violation
                                                                               * BUG: Even though the comment is ignored */ thisIsALongVariableToTestChecker); // @violation
    }
}