package cc;

public class EmptyWhileStatement {
    public void function() {
        while (true) {
            int a = 0;
        }

        while (true) {  // @violation

        }

        while (true) {}  // @violation

        while (true);   /* SAFE */
    }

}