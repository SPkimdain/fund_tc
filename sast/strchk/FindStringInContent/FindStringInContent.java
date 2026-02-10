package com.sparrow;

import java.lang.String;

/**
 * @author 0
 * @version 1.0
 * @since 2021-01-19
 */
class Main {
    public void forbiddenFunc() {       // violation -> forbidden을 검출한다고 지정했을 경우
        int a;
        a = 1;
    }
}