package com.fasoo.javafinch.syn.checker.cc;

/**
 * this is long long long very long
 * long line in the middle of block comment long line in the middle of block comment long line in the middle of block comment // @violation
 * comment
 */
public class MaxLineLength {
    // Good
    public static void longLongVeryLongMethodName(int longLongVeryLongParameterNames, String test) {

    }

    protected final MaxLineLengthTest longLongVeryLongPureExcess(int number, String strictViolence) { // @violation
        return this;
    }

    protected final MaxLineLengthTest longLongVeryLongPureExcessNotStrict(int number, String tooLongHaha) { // @violation
        return this;
    }

    public static void excessByLineCommentTest(int test1, String test2) { // single line comment is long but may be allowed by option // @violation

    }

    public static void excessByBlockCommentTest(int test1, String test2) { /* block comment is long but may be allowed by option */ // @violation

    }

    // this is long line comment this is long line comment this is long line comment this is long line comment this is long line comment // @violation

    /* this is long block comment this is long block comment this is long block comment this is long block comment */ // @violation
}
