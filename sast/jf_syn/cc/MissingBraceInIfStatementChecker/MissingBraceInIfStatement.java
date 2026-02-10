package cc;

public class MissingBraceInIfStatement {
    public int func(int a, int b, int c) {
        if(a > b) {
            return 0;
        }

        if(a < b)
            return 1; // @violation

        if(a == b) {
            if(b == 0) {
                return -1;
            } else
                return -2; // @violation

            if(c == 0) {
                return 2;
            } else if(c == 1)
                return 3; // @violation

            if(c == 2) {
                return 10;
            } else if(c == 3) {
                return 11;
            } else
                return 12; // @violation
        }
    }
}
