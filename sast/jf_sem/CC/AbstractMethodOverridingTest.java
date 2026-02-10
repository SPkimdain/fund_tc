package cc;

/**
 * User: starblood
 * Date: 5/24/13
 * Time: 5:59 PM
 *
 * Abstract class 를 overriding 하는 경우에, overridden method 에서 infinite recursive call 이 나타나지 않는 것을 테스트
 */
public class AbstractMethodOverridingTest extends AbstractClass<Foo> {
    public Foo getObject() {
        return new Foo();
    }
}

abstract class AbstractClass<T> {
    public abstract T getObject();
}

class Foo {

}
