package cc;

public class BadWhitespaceForStatement {
    public void func() {
        int i,j;

        for(i=0; i<10; i++) {
            // Do something ...
        }

        for (i=0;i<10; i++) { // @violation
            // Do something ...
        }

        for (i=0; i<10;i++) { // @violation
            // Do something ...
        }

        for (i=0, j=0;i<10;) { // @violation
            // Do something ...
        }

        for (i=0;;i++) { // @violation
            // Do something ...
        }

        for (i=0; i<10; i++) { /* SAFE */
            // Do something ...
        }
    }
}