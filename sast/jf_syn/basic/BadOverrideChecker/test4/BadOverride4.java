package test4;

import two.Empty;

/**
 * BAD_OVERRIDE Test case 4 : More complex parameters
 * 보다 복잡한 메소드 파라미터 형식 (배열, 사용자 정의 클래스 타입 포함)
 * @author JWYoon
 *
 */
public class BadOverride4 extends Parent {
    public int[] method(String[] x, int y, Empty[] z) { // @violation
        return new int[y];
    }
}
