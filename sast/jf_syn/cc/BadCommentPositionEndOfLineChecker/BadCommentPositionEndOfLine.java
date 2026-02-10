// COMMENT.POSITION.END_OF_LINE
package cc;

public class BadCommentPositionEndOfLine {

    // Comment1 // @violation
    // Comment2
    private int a;

    public void func(boolean cond, int iCond) {
        switch(iCond) {
        case 0:
            // Comment3
        case 1:
            // Comment4 // @violation
            break;  // Comment5
        case 2:
            break;  // Comment6
        default:    /* test */
            break;  /* test */
        }
    }
}
// Comment7
// Comment8
// Comment9