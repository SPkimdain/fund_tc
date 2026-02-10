// WHITESPACE.INC_DEC_EXPRESSION
package cc;

public class BadWhitespaceIncDecExpression {
    public void goodTest() {
        int num1 = 1;
        num1 ++;   // @violation
        num1 --;   // @violation
        ++ num1;   // @violation
        -- num1;   // @violation

        num1++;    /* SAFE */
        num1--;    /* SAFE */
        ++num1;    /* SAFE */
        --num1;    /* SAFE */

        for(int i = 0; i < 10; i ++) { // @violation

        }

    }

}