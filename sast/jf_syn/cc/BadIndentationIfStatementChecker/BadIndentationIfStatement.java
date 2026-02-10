package cc;

public class BadIndentationIfStatement {

    public void doSomething() {
        // Do something ...
    }

    public void func(boolean cond1, boolean cond2, boolean cond3, boolean cond4) {
        if((cond1 && cond2) || (cond3 && cond4)) {
            doSomething();
        }

        if((cond1 && cond2) ||
           (cond3 && cond4)) { 			// @violation
            doSomething();
        }

        if((cond1 && cond2) ||
                (cond3 && cond4)) { 	// @violation
            doSomething();
                    doSomething();
        }

        if((cond1 && cond2) ||
                (cond3 && cond4)) {
            doSomething();
        }
    }
}
