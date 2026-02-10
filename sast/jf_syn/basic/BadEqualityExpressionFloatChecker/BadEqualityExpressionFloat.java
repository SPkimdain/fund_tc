package basic;

public class BadEqualityExpressionFloat {

    public float fFunc() {
        float a;
        // Do something ...
        return a;
    }

    public int iFunc() {
        int b;
        // Do something ...
        return b;
    }

    public void test(int i, float f) {
        if(i == 2) {
            // Do something ...
        } else if(f == 2) { // @violation
            // Do something ...
        }

        if((float)i != 2) { // @violation
            // Do something ...
        } else if((int)f == 2) {
            // Do something ...
        }

        if(iFunc() != 2) {
            // Do something ...
        } else if(fFunc() == 2) { // @violation
            // Do something ...
        }

        if((double)iFunc() != 2) { // @violation
            // Do something ...
        } else if((int)fFunc() == 2) {
            // Do something ...
        }
    }
}