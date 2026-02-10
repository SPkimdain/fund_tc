package com.sparrow;

import java.lang.String;

public class People {
    // int 타입 변수: 나이
    private int age;
    /* String 타입 변수: 이름 */
    private String name;
    /* String 타입 변수: 
	 * 주소 
	 */
    private String address;

    public String getName() {
        return this.name;
    }
    public void setName(String name) {
        this.name = name;
    }
}