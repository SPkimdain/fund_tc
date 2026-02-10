package test.com.fasoo.javafinch.syn.rule.basic.setstaticinnonstatic;

/**
 * SET_STATIC_IN_NON_STATIC Test case 3 : Different Scope
 * Static field가 현재 scope이 아닐 경우(Non-static variable이 현재 scope일 경우) 오류 아님
 * @author JWYoon
 *
 */
public class SetStaticInNonStatic3 {
    private static SetStaticInNonStatic3 instance;

    public SetStaticInNonStatic3 method() {
        SetStaticInNonStatic3 instance;

        instance = this; // Not bug

        return instance;
    }

    public SetStaticInNonStatic3 getInstance() {
        return instance;
    }
}
