package scaffold.rl.assign;

import java.io.FileInputStream;

/*
 *  아래 코드는 FileLib 의 getStream method 로 resource 를 할당 받은 후,
 *  이 resource 를 해제하는 코드가 없기 때문에 Resource Leak alarm 이 발생하는 것을 보여준다.
 *  Note: Test.scaffold 파일을 없애면, Resource Leak alarm 이 발생하지 않는다.
 */
public class Test {
    public void test() {
        FileLib lib = new FileLib();

        try{
            FileInputStream fis = lib.getStream();
            /* BUG */
        } catch (Exception e) {}
    }
}
