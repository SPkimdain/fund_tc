package com.example.service;

import java.io.IOException;

public class ServiceImpl {
    public void process() {
        String x = "foo";
        if (x.equals(null)) {  //@violation
            System.out.println();
        }
    }
}

