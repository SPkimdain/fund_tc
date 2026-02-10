package com.example;

public class UnusedVariableTestCase {

    private String usedVariable = "Hello";
    private String unusedVariable = "Not Used";  //@violation

    public void exampleMethod() {
        System.out.println(usedVariable);
    }
}
