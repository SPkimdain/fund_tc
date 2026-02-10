// 주석 테스트
package cc;

public class BadCommentPositionSingle {

    public A A;
    public int iField;

    // Good comment
    public String sField;

    public int i = -1;
    // @violation comment
    public String filed2;

    // commnet test
	// comment test2
    public void func() {
        A A;
        int a = 0;

    // @violation indentation

        int b = 0;

        // Good indentation

    }
	public void func2() {

	    // commnet test
		// comment test2
    	// comment test2
		if(iField == 1) {
            String pass = null;	//test3
            int x = 10;         // test1
        int y = 0;			    // test2
		}
	}
	
}