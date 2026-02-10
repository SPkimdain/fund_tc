package ti;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.Properties;
import java.lang.Runtime;
import javax.servlet.http.*;
/**
 * Writer: Gyuhang Shim
 * Date: 5/2/12
 */
/* OPT : -show_followers */
public class COMMAND_INJECTION_TestCase {
    public void test(HttpServletRequest request) throws IOException {
        Properties props = new Properties();
        String fileName = "file_list";
        FileInputStream in = new FileInputStream(fileName);
        props.load(in);
        in.close();
        String version = props.getProperty("dir_type");
        version = request.getParameter("dir_type");
        String cmd = new String("cmd.exe /K \"rmanDB.bat \"");
        Runtime.getRuntime().exec(cmd + " c:\\prog_cmd\\" + version); /* BUG */

        String [] env = {"OS=Windows", "JVM=1.6"};
        Runtime.getRuntime().exec("abc-" + version + ".exe", env); /* BUG */
    }
    public void test2(HttpServletRequest request, Properties props) throws IOException {
        String version = props.getProperty("version");
        version = request.getParameter("version");
        ProcessBuilder pb1 = new ProcessBuilder(version, "arg1", "arg2"); /* BUG */
        ProcessBuilder pb2 = new ProcessBuilder("arg1", version, "arg2"); /* BUG */
        ProcessBuilder pb3 = new ProcessBuilder("arg1", "arg2", version); /* BUG */
    }
    int getSomeInt() {return 2;}
    String taintString(HttpServletRequest request, Properties props) {
        if (getSomeInt() > 1)
            return request.getParameter("dir_type");//props.getProperty("dir_type");
        else
            return "abc";
    }
    public void testComplicated(HttpServletRequest request) throws IOException {
        Properties props = new Properties();
        String fileName = "file_list";
        FileInputStream in = new FileInputStream(fileName);
        props.load(in);
        in.close();

        String version;

        if (getSomeInt() > 3) {
            version = "abc";
        } else {
            version = props.getProperty("dir_type"); // tainted
            version = request.getParameter("dir_type");
        }

        String cmd = new String("cmd.exe /K \"rmanDB.bat \"");
        Runtime.getRuntime().exec(cmd + " c:\\prog_cmd\\" + version); /* BUG */

        String tail = taintString(request, props);
        Runtime.getRuntime().exec(cmd + " c:\\prog_cmd\\" + tail); /* BUG */
    }
}
