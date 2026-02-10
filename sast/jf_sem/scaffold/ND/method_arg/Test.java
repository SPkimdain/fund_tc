package scaffold.nd.method_arg;

/*
 *  아래 클래스는 특정 클래스의 method 의 인자로 null 값이 들어갈 경우,
 *  ND alarm 을 발생시키는 것을 표현하기 위한 테스트 클래스이다.
 *  Note: Test.scaffold 파일이 없을 경우, ND alarm 이 발생하지 않는다.
 */
public class Test
{
    public void test() {
        StringLib lib = new StringLib();
        lib.doSomething(null); /* BUG */
    }
}
