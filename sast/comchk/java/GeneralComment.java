package com.sparrow;

import java.lang.String;

public class People {
    private int age;
    private String name;
	private String address;

    public String getName() {
        /* name을 리턴하는 부분 */
        return this.name;
        /*
         * 실행 안되는 부분
         */
    }
    public void setName(String name) {
        // name값을 set하는 부분
        this.name = name;
    }
}