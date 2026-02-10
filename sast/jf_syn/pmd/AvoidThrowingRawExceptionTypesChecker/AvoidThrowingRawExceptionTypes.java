package src.test.java.pmd;

import java.lang.*;
import java.lang.Throwable;
import java.lang.Exception;
import java.lang.Error;
import java.lang.RuntimeException;

public class AvoidThrowingRawExceptionTypes {
    public void fun1() throws Exception {
        throw new Exception(); // @violation
    }

    public void fun2() throws Exception {
        Exception a = new Exception();
        throw a; // @violation
    }

    public void fun3() throws Exception {
        throw new RuntimeException(); // @violation
    }
    public void bar() throws IOException{
        throw new IOException();
    }
}