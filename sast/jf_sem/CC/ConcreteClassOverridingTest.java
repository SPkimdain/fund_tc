package cc;

/**
 * User: starblood
 * Date: 5/27/13
 * Time: 9:49 AM
 *
 * Concrete class 를 overriding 하는 경우에, overridden method 에서 infinite recursive call 이 나타나지 않는 것을 테스트
 */
public class ConcreteClassOverridingTest extends ConcreteClass {
    public int getFib(int i ) {
        return i;
    }
}

class ConcreteClass {
    public int getFib(int i) {
        return getFib(i - 1) + getFib(i -2); // 2 infinite recursive call
    }
}