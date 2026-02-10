package scaffold.rl.simple_test;

import java.lang.System;

/**
 * 아래의 코드는 Resource Leak 관련 분석 Test case 이다.
 * 아래의 코드에서 rs1, rs2 는 Manager.getResult() 이라는 동일한 일을 수행하는 method 를 overloading 하여
 * Resource 를 할당 받는다.
 * 관련 scaffold file: scaffold_Test2.txt
 */
public class Test2 {
    public static void test2() {
        Manager m = null;
        ResultSet rs1 = null, rs2 = null;
        try {
            m = new Manager(); // resource 할당
            rs1 = m.getResultSet(); // resource 할당
            rs2 = m.getResultSet(2); // resource 할당

			ResultSet.zoo(rs1);
        }
		catch(RuntimeException e) {
			int a = 1;
		}
		catch(Exception e) {
		}
        finally {
            if(m != null) {
                m.CommitAndclose();
            }
            // rs1, rs2 의 resource 가 해제되어야 하는 코드가 없다.
            // 그러므로 테스트의 결과는 Resource Leak alarm 이 두 개가 나와야 한다.
            // 하지만 아직 분석기 엔진에서 두개의 alarm 이 따로 나오지 않고 합쳐져서 결과는 1개만 출력된다.
        }
    }
}