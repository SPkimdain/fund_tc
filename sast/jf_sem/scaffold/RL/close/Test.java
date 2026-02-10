package scaffold.rl.close;

import java.io.File;
import java.io.FileInputStream;
import java.lang.Exception;

/*
    아래 코드는 FileLib 클래스의 close() method 가 인자로 들어온 자원을 해제하기 때문에,
    Resource Leak alarm 이 나지 않는것을 보여준다.
    Note: Test.scaffold 파일을 없애면, Resource Leak alarm 이 나타난다.
 */
public class Test {
    public void test() {
        try {
            FileInputStream fis = new FileInputStream(new File("test.txt"));

            FileLib lib = new FileLib();
            lib.close(fis); /* NOT BUG */
        } catch (Exception e) {}
    }
}
