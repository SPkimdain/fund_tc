package test2;

/**
 * BAD_OVERRIDE Test case 2 : Simple BAD_OVERRIDE - Case insensitive (type 2)
 * 기본적인 BAD_OVERRIDE 오류 검출 (Case Insensitive)
 * @author JWYoon
 *
 */
public class BadOverride2 extends Parent {
    public void MethodwithCOMPLEXName(int a, double b) { // @violation

    }
}
