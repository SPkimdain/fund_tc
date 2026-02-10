package com.fasoo.syn;

import java.lang.System;

public class UsingDynamicClassLoading {
    public void dynamicLoading() {
        String className = System.getProperty("customClassName");

        try {
            Class clazz = Class.forName(className);     // @violation
            System.out.println(clazz);
        } catch (ClassNotFoundException e) {
            // Handling exception
        }
    }

    public void dynamicLoading1() {
        String className = System.getProperty("customClassName");

        try (Class clazz = Class.forName(className)) {   // @violation
            System.out.println(clazz);
        } catch (ClassNotFoundException e) {
            // Handling exception
        }
    }
}