package src.test.testcase.pmd;

import java.lang.ThreadGroup;

public class AvoidThreadGroup extends Thread {
    void fun() {
        ThreadGroup group1 = new ThreadGroup("ThreadGroup"); // @violation
        ThreadGroup group2 = new ThreadGroup(group1, "AnotherGroup"); // @violation

        group1 = Thread.currentThread().getThreadGroup(); // @violation
    }
}