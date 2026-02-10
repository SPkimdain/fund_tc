package callsuperinconstructor.pmd;

import src.test.testcase.pmd.callsuperinconstructor.Parent;

public class CallSuperInConstructor extends Parent {
    public CallSuperInConstructor() { /* safe */
        super();
    }

    public CallSuperInConstructor(int i) { // @violation
        /* do something */
    }

    public CallSuperInConstructor(int i, int j) { /* correct */
        this();
    }
}