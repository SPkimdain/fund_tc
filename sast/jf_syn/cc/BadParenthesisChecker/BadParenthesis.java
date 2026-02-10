package cc;

import java.lang.String;

public class BadParenthesis {

    private int a = (1 + 2 ); // @violation

    private class BadInner {
        private int ic = ((1 + 2) ); // @violation

        public void innerFunc() {
            int i = 0;
            do {
                // Do something
            } while( i++ );
        }
    }

    public void func() {

        while( true ) {
            // Do something ...
        }

        while(true) { // @violation 2
            // Do something ...
        }

        // Parenthesis in the comment (
        // Parenthesis in the comment ( ) (( ) (

        char temp = '(';
        String tempStr = "( ... ()" + "))";

        int a = ( 3 + 4 );
        int b = (3 + 4 ); // @violation
        int c = ( 3 + 4); // @violation

        int x = ( (3 + 4) + 5 );
        int y = ( ( 3 + 4 ) + 5 );
        int z = (( 3 + 4 ) + 5); // @violation 2
        char tt = ( '(' + 5 ) + ')';

        for( int i=0;
            i<10;
            i++
           ) { /* SAFE */
            // Do something ...
        }

        for( int i=0;
             i<10;
       i++ ) { // @violation
            // Do something ...
        }

        for( int i=0;
            i<10;
            i++ ) { // @violation
            // Do something ...
        }
    }
}
