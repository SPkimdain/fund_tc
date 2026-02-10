package scaffold.rl.assign;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;

/**
 * Test class 가 compile 되기 위한 stub class
 * 이 클래스의 getStream() method 는 Test.scaffold 파일에 정의되어 있다.
 */
public class FileLib {
    public FileInputStream getStream() throws IOException {
        File file = new File("test.txt");
        return new FileInputStream(file);
    }
}
