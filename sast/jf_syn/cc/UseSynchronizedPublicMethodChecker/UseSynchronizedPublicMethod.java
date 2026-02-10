package cc;

import java.lang.System;

public class UseSynchronizedPublicMethod {
    private int field;

    private void privateMethod() { /* SAFE for private method */
        field++;
    }

    public void publicMethod() { // @violation
        field++;
    }

    public void publicMethod2() { // @violation
        System.out.println(field);
    }

    public void publicFMethod() {
        int local;
        local++;
    }

    public synchronized void publicFSyncMethod() {
        field++;
    }
}
