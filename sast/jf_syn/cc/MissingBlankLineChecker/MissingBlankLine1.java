package cc;

import java.io.*;


public class MissingBlankLine { // @violation

    public class A {

    }


    public class B {
        public void test1() {}
    }



    public class C {
        public void test2() {}
    }

    MissingBlankLine() {

    }

    /**
     *
     * @param condition
     * @param x
     * @param y
     * @return
     */
    public int func(boolean condition, int x, int y) {
        int a;
        int b;
        Runnable runner2;
        Runnable runner;

        //comment
        runner2 = new Runnable() {

            /**
             * Runnalble 무명 함수
             */
            @Override
            public void run() {
                return;
            }
        };

        //comment
        runner = new Runnable() {

            /**
             * Runnalble 무명 함수
             */
            @Override
            public void run() {
                return;
            }
        };

        return condition ? x : y;
    }

    public boolean func2(boolean condition) {
        int a;
        int b;
        return condition; // @violation
    }

    public int func3(boolean condition, int x, int y) {
        if(condition) {
            return x;
        } else {
            return y;
        }
    }


    public boolean func4(boolean condition, int x, int y) { // @violation
        if(condition) {
            return true;
        }
        return false;
    }

    MissingBlankLine(int a) {

    }

    /**
     * MD tjqltm
     * comment
     */
    public boolean func4(boolean condition, int x, int y) {
        if(condition) {
            return true;
        }
        return false;
    }

    private int tempa;
    private int tempb;

    /**
     * MD tjqltm
     * comment
     */
    public boolean func4(boolean condition, int x, int y) {
        if(condition) {
            return true;
        }
        return false;
    }

    boolean func5(boolean condition, int x, int y) {
        if(condition) {
            return true;
        }
        return false;
    }

}


public interface interfaceA {

}



public interface interfaceB { // @violation

}
