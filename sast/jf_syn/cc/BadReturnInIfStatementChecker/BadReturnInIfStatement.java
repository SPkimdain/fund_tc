// RETURN_IN_IF_STATEMENT
package cc;

public class BadReturnInIfStatement {

    public boolean func(boolean b) {
        if(b) {
            return true;    // @violation
        } else {
            return false;   // @violation
        }
    }

    public int func(int i) {
        if(i == 1) {
            return 4;   // @violation
        } else if(i == 2) {
            return 6;   // @violation
        } else {
            return 0;   // @violation
        }
    }

    public int func(int i) {
        if(i == 1) {
            return 4;   // @violation
        }
        return 0;
    }

    public int func(int i) {
        if(i == 1)
            return 4;   // @violation
        else
            return 0;   // @violation

    }

    public int func(int i) {
        if(i == 1) {
            i = 4;
            return i;
        } else {
            i = 6;
            return i;
        }

    }

    public int func(int i) {
        int i1 = (int i2) -> {
            if (i2 == 1) {
                i = 4;
                return i;
            } else {
                i = 6;
                return i;
            }
        };
    }

    public int func(int i) {
        int i1 = (int i2) -> {
            if (i2 == 1) {
                return 4;    // @violation
            } else {
                return 6;    // @violation
            }
        };
    }
}