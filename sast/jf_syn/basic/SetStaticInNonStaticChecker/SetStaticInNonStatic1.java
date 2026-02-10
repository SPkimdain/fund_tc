package test.com.fasoo.javafinch.syn.rule.basic.setstaticinnonstatic;

/**
 * SET_STATIC_IN_NON_STATIC Test case 1 : Simple SET_STATIC_IN_NON_STATIC
 * 기본적인 SET_STATIC_IN_NON_STATIC 오류 검출
 * @author JWYoon
 *
 */
public class SetStaticInNonStatic1 {
    private static int staticInt;

    public static int staticMethod(int x) {
        staticInt = x; // Not bug
        return staticInt;
    }

    public int method(int x) {
        staticInt = x; // @violation
        return staticInt;
    }
}