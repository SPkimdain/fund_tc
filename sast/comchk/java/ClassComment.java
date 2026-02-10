package com.sparrow;

import java.lang.String;

/**
 * People 클래스
 * @author 김지환
 * @version 1.0
 * @bad comment
 * @since 2021-01-19
 */
public class People {
    private int age;
    private String name;
	private String address;

    public String getName() {
        return this.name;
    }
    public void setName(String name) {
        this.name = name;
    }
}