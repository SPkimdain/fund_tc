package cc;

public class EmptyBranch {

    public void func(boolean cond, int flag) {
        if(cond) {
            // Do something ...
        }

        if(cond) {
            // Do something ...
        } else; // @violation

        if(cond)
            ;
        else
            ; // @violation

        if(cond) {
            // Do something ...
        } else { // @violation
            // Do something ...
        }

        if(cond) {
            // Do something ...
        } else if(flag < 0) {
            // Do something ...
        } else { // @violation

        }

        if(cond) {

        } else {
            if(flag > 0) {
                if(flag > 5) {

                } else; // @violation
            } else if(flag == 0) {
                // Empty
            } else {
                if(flag < -5) {

                }
            }
        }

        int x;
        switch(cond) {
            case 0:
                x = cond;
                break;
            case 1: // @violation
            case 2:
                x = cond + 1;
                break;
            default: // @violation
                // Empty
        }

        switch(cond) {
            case 0:
                x = cond;
                break;
            default:
                x = cond-1;
                break;
        }
    }

}
