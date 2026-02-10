package com.test;

import java.util.ArrayList;

public class ToStringExample {
    public static void main(String[] args) {
        String sss = "Hello";

        String s = new String("example"); //@violation

        ArrayList<String> list = new ArrayList<>();

        System.out.println(s);
    }
}
