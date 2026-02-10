package com.test;

public class unprocessedExceptionThrow {
    public static void main(String[] args) throws Exception { //@violation
        String s = "Hello";

        String result = s.toString();
        if (result != null && result.trim().length() == 0) {
            System.out.println(result);
        }
    }
}
