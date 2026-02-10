package rl;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.Enumeration;
import java.util.Properties;

public class ClazzResourceTest {
    /*
        apache-ant-1.8.4 의 Diagnostics.java 에서 doReportTasksAvailability 메소드를 분석하기 위해 소스를 약간 변형함
        java.lang.Class.getResourceAsStream 에서 자원이 할당되지만, 해제하는 코드가 없어서 Resource Leak 이 발생하는 것을
        검출하기 위한 테스트 케이스
     */
    private static void doReportTasksAvailability(PrintStream out) {
        InputStream is = ClazzResourceTest.class.getResourceAsStream(
                "abc"); // Resource allocation
        if (is == null) {
            out.println("None available");
        } else {
            Properties props = new Properties();
            try {
                props.load(is);
                for (Enumeration keys = props.keys(); keys.hasMoreElements();) {
                    String key = (String) keys.nextElement();
                    String classname = props.getProperty(key);
                    try {
                        Class.forName(classname);
                        props.remove(key);
                    } catch (ClassNotFoundException e) {
                        out.println(key + " : Not Available "
                                + "(the implementation class is not present)");
                    } catch (NoClassDefFoundError e) {
                        String pkg = e.getMessage().replace('/', '.');
                        out.println(key + " : Missing dependency " + pkg);
                    } catch (LinkageError e) {
                        out.println(key + " : Initialization error");
                    }
                }
                if (props.size() == 0) {
                    out.println("All defined tasks are available");
                } else {
                    out.println("A task being missing/unavailable should only "
                            + "matter if you are trying to use it");
                }
            } catch (IOException e) {
                out.println(e.getMessage());
            }
        }
    } /* BUG */ // Resource Leak

    /*
        apache-ant-1.8.4, ProjectHelperRepository.java 의 collectProjectHelpers() 메소드를 분석기가 검출하기 좋게 수정
        Klocwork 에서만 검출되던 Resource Leak 을 Sparrow 에서도 검출 가능하도록 Semantics 를 추가하기 위한 테스트 케이스
     */
    private void collectProjectHelpers() {
        try {
            Object projectHelper = null;
            InputStream systemResource =
                    ClassLoader.getSystemResourceAsStream("ABC"); // Resource allocation
            if (systemResource != null) {
                projectHelper = new Object();
            }
        } catch (Exception e) {

        }
    } /* BUG */ // Resource Leak
}