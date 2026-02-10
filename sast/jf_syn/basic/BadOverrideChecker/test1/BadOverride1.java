package test1;

import two.Empty;

/**
 * BAD_OVERRIDE Test case 1 : Simple BAD_OVERRIDE - Different imported packages
 * 기본적인 BAD_OVERRIDE 오류 검출 (Import 패키지 명이 다를 경우)
 * @author JWYoon
 *
 */
public class BadOverride1 extends Parent {
    public void method(Empty e) { // @violation

    }
}
