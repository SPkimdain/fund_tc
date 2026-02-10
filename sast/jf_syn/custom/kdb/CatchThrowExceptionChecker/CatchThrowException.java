package com.example.service;

import java.io.IOException;

public class ServiceImpl {
    public void process() {
        try {
            throw new IOException("Some error");
        } catch (IOException e) {
            throw new RuntimeException("Custom message"); //@violation
        }
    }
}

public class ValidService {
    public void process() {
        try {
            throw new IOException("Some error");
        } catch (IOException e) {
            throw new RuntimeException("Custom message", e); //safe
        }
    }
}
