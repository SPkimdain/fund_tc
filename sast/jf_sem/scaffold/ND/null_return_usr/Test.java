package scaffold.nd.null_return_usr;

/*
 * 이 클래스는 사용자 정의 library 로부터 null 이 return 될 가능성이 있는
 * 변수(str) 을 dereference 해서 NULL_RETURN_USR alarm 이 발생하는 것을 보여준다. 
 */
public class Test
{
    public void test() {
        Library lib = new Library();
        String str = lib.getString(); // null 이 반환될 수도 있다.

		/* NULL_RETURN_USR : null 이 반환될 수도 있는 값을 null 검사를 하지 않고
		   사용하는 것은 위험하다. */
        str.toUpperCase(); /* BUG */
    }
}

