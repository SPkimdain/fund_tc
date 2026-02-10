package scaffold.rl.simple_test;

public class Test {
    public static void test() {
        Manager m = null;
        ResultSet rs = null;
        try {
            m = new Manager(); // Constructor 에 의해서 resource 할당
            rs = m.getResultSet(); // Manager.getResultSet() 에 의해서 resource 할당

			return;
        }
		catch(RuntimeException e) {
			int a = 1;
		}
		catch(Exception e) {
			rs.close();
		}
        finally {
            if(m != null) {
                // Resource 해제하는 코드가 없어서 resource Leak 이 발생
                //m.CommitAndclose();
            }
            if(rs != null) {
                // Resource 해재하는 코드가 없어서 resource Leak 이 발생
                //rs.close();
                //m.CommitAndclose();
            }
        }
    }
}
