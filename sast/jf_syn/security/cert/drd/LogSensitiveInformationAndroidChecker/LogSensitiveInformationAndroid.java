package src.test.testcase.security;

import java.lang.*;
import android.util.*;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Properties;

public class LogSensitiveInformationAndroid {
    private int iValue;
    private String sValue;

    public int getIntValue() {
        return this.iValue;
    }
    public void setIntValue(int i) {
        this.iValue = i;
    }

    public String getstrValue() {
        return this.sValue;
    }

    public void setStrValue(String s) {
        this.sValue = s;
    }

    public void printAndLog() {
        Properties pro= new Properties();
        try {
            pro.load(new FileInputStream("C:\\test\\sample2.properties"));
            android.util.Log.d("string test", pro.getProperty("test.select")); // @violation
            android.util.Log.println(0, "string test", pro.getProperty("test.pro")); // @violation
        } catch (Exception e) {

        }

    }
}