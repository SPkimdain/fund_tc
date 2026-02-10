package test.com.fasoo.javafinch.syn.rule.basic.setstaticinnonstatic;

/**
 * SET_STATIC_IN_NON_STATIC Test case 2 : Simple SET_STATIC_IN_NON_STATIC in Constructor
 * 생성자에서의 기본적인 SET_STATIC_IN_NON_STATIC 오류 검출
 * @author JWYoon
 *
 */
public class SetStaticInNonStatic2 {
    private static SetStaticInNonStatic2 staticInstance;

    public SetStaticInNonStatic2 () {
        staticInstance = this; // @violation
    }

    public SetStaticInNonStatic2 getInstance() {
        return staticInstance;
    }
}
