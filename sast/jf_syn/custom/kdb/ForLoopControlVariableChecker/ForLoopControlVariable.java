package com.example;

public class ForLoopControlVariable {

    public void forLoop() {
        float i = 0.0;

        for(i=0.0; i<1.0; i=i+0.1){
            System.out.println();
        }

        for (double x = 0.1; x < 1.0; x += 0.1) {
            System.out.println(x);
        }
    }
}
