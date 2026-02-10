package cc;

import java.util.ArrayList;

/*
 * comment for TEST
 * @author TESTER
 * @version 1.0
 * Don't care about next line
 */
public class BadCommentPositionBlock {

    public A b;
    /* // @violation
     * BAD: need upper blank line
     */

    public A A;

/* // @violation
 * Bad indentation
 */

    /* // @violation
      * Don't care about next line
     */
    public int iField;

    // Single line comment
    public String sField;

    public void func() { // Trailing comment
        A A;

        /*
         * next line is closing brace, no problem
         */
    }

    public void func2() {
        A b;

    /* // @violation
     * BAD: next line is closing brace, comment need deeper indent
     */
    }
}
