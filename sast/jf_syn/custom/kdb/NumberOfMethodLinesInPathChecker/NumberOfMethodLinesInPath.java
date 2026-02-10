package com.example;

public class UnusedVariableTestCase {

    private String usedVariable = "Hello";
    private String unusedVariable = "Not Used";

    public void exampleMethod() {
        System.out.println(usedVariable);
        System.out.println(usedVariable);
    }
}
