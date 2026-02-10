package cc;

public class BadWhitespaceCall {

    public int iFunc(int a, int b) {
        // Do something ...
        return a+b;
    }

    public void vFunc(int a, int b, int c) {
        // Do something ...
    }

    public void eFunc() {
        // Do something ...
    }

    public void test() {

        vFunc(1, 2, 3); /* SAFE */
        vFunc( 1,2, 3 ); // @violation
        vFunc( 1+2, 2+3,3+4 ); // @violation
        vFunc( 1,iFunc( 1, 2 ), 3 ); // @violation
        vFunc( 1, iFunc( 1,2 ), 3 ); // @violation
        vFunc( 1 + iFunc( 1,2 ), 3 + iFunc( 4, 5 ), 6 ); // @violation
        vFunc( 1+iFunc( 1, 2 ), 3+iFunc( 4, 5 ), 6 ); /* SAFE */

        eFunc(); /* SAFE */
        eFunc( ); // @violation

        vFunc ( 1, 2, 3 ); // @violation
        eFunc (); // @violation

        vFunc( 1 , 2, 3 ); // @violation
        vFunc( 1 ,2, 3 ); // @violation

        vFunc( 1 , /* @violation */

                2 , 3 ); // @violation
        vFunc( 1,
               2, 3 );
    }
}
