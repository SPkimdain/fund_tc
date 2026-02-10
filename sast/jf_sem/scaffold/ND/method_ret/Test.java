package scaffold.nd.method_ret;

/*
 *  아래 코드는 StringLib 클래스의 getString() method 가 null 값을 return 하기 때문에,
 *  11 번째 라인에서, ND alarm 이 발생하는 것을 보여준다.
 *  Note: Test.scaffold 파일을 없애면 ND alarm 이 발생하지 않는다.
 */
public class Test
{
    public void test() {
        StringLib lib = new StringLib();
        String str = lib.getString(); // StringLib.getString() 은 null 을 return 한다.

        str.toLowerCase(); /* BUG */
    }
}
