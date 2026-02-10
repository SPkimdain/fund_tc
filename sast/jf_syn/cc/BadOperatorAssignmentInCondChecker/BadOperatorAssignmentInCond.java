package cc;

public class BadOperatorAssignmentInCond {
    public void func(int x, int y) {
        if(x == y) {
            // Do something ...
        }

        if(x = y) { // @violation
            // Do something ...
        }

        if(x++ = y++) { // @violation
            // Do something ...
        }

        if((x = y)) { // SAFE since the parenthesis is used
            // Do something ...
        }

        if((c++ = d++) != 0) {
            // Do something ...
        }
    }


}
