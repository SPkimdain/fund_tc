package com.sparrow;

import java.lang.String;

public class People {
    private int age;
    private String name;
	private String address;

    /**
     * name 값을 반환하는 함수
     *
     * @return 반환값
     * @since 2021-01-19
     */
    public String getName() {
        return this.name;
    }

    /**
     * name 값을 설정하는 함수
     *
     * @param name1 String 타입
     * @since 2021-01-19
     */
    public void setName(String name) {
        this.name = name;
    }
}