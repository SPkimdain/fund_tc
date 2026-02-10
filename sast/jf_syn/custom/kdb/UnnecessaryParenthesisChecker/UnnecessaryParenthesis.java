package com.example;

public class UnnecessaryParenthesisTest {

    public void testParenthesis() {
        int n = 10;

        int bar1 = Integer.valueOf((n));  //@violation
        int bar2 = (n);  //@violation

        int valid1 = (n + 1);  // ✅ 정상 (우선순위 변경 목적)
        int valid2 = (n * 2 + 5);  // ✅ 정상
    }

    public void testMethodCall() {
        String msg = "Hello";
        printMessage((msg));  //@violation
        printMessage(msg);  // ✅ 정상
    }

    public void printMessage(String message) {
        System.out.println(message);
    }
}
