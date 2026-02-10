package com.example;

public class MessageCodeTestCase {

    public void testLogMessage() {
        logMessage("BEGSB1234", e);
        logMessage("BES1234");
    }
    public void logMessage(String messageCode) {
        System.out.println("Logging message: " + messageCode);
    }
}
