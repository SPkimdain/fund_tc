package cc;

/** //@violation
 * 문서키채번호출을 수행하는 클라이언트 BIZ
 * @stereotype Biz
 * @name_ko 문서키채번클라이언트BIZ
 * @since 2025-02-26 15:52:48
 */
public class BadNameVariable {
    private int BadName; // Bad
    public final static String[] str = new String[] {};/* BUG */
    public static final String stringConstant = "CONSTANT"; // Bad
}

/** //@violation
 * 문서키채번호출을 수행하는 클라이언트 BIZ
 * @author 김태호
 * @stereotype Biz
 * @name_ko 문서키채번클라이언트BIZ
 */
public class FallThroughExample {
    public void foo(int a) {
        switch (a) {
            case 0:
            case 1: // Bad: break 없음
            case 2:
                System.out.println("Case 2 or fall-through from 0, 1");
                break;
            default:
                System.out.println("Default case");
                break;
        }
    }

    public static void main(String[] args) {
        FallThroughExample example = new FallThroughExample();
        example.foo(0); // Bad: case 0부터 case 2까지 이어짐
        example.foo(1); // Bad: case 1부터 case 2까지 이어짐
        example.foo(2); // 정상: case 2만 실행
        example.foo(3); // default 실행
    }
}