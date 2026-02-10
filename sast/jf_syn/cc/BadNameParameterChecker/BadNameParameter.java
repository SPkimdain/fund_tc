package cc;

public class BadNameParameter {
    public void badFunc(int iParam) { // @violation
        // Do something ...
    }

    public void anotherBadFunc(int pParam, double dparam) { // @violation
        // Do something ...
    }

    public void goodFunc(int pParam) {
        // Do something ...
    }

}