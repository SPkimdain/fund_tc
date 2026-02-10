package scaffold.rl.close;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;

/*
    Test class 가 compile 되기 위한 stub class
    이 클래스의 close() method 는 Test.scaffold 파일에 정의되어 있다.
 */
public class FileLib {
    /*
        인자로 들어온 FileInputStream type 의 자원을 해제한다.
     */
    public void close(FileInputStream fis) throws IOException {
        fis.close();
    }
}
