package foo;
import foo.TempClass;       //@violation
import java.util.ArrayList;
import java.util.HashMap;    //@violation
import java.util.*;          //@violation

public class ImportTest {
    public void testMethod() {
        List<String> list = new ArrayList<>();

        // foo.temp 사용 예시
        TempClass temp = new TempClass();
        temp.doSomething();
    }
}
