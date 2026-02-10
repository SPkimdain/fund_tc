package com.example;

public class ModifyParameterTest {

    public void modifyData(Data inputData) {
        inputData.set("key", "value");
    }

    public void safeMethod(Data inputData) {
        Data copiedData = inputData.clone();
        copiedData.set("key", "value");
    }
}
