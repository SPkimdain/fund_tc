package com.example;

public class UnusedMethodTest {

    private void unusedMethod() {   //@violation
        System.out.println("Unused method");
    }

    private testConstructor() {
    }

    private void usedMethod() {
        System.out.println("Used method");
    }

    public void callerMethod() {
        usedMethod();
    }
}
