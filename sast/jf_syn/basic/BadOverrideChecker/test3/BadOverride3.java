package test3;

import two.Empty;

/**
 * BAD_OVERRIDE Test case 3 : Different imported packages - Array type parameter
 * Import 패키지 명이 다를 경우, 파라미터로 해당 타입의 배열 사용
 * @author JWYoon
 *
 */
public class BadOverride3 extends Parent {
    public void method(Empty[] e) { // @violation

    }
}
