/**
 * 본 테스트 코드를 확실하게 확인 하기 위해서는 
 * 메모장에서 Indentation이 맞는지 확인해야합니다.
 * @author Byungho
 *
 */

class foo {
///////////////////////////////////////////////////////////////////////////////////////////////
	
   void doSomethingAboutIt(String pMgmtNo, String pAddrCode, String CauseCode) {   /* Safe */
   } 
   void doSomethingAboutIt(String pMgmtNo , String pAddrCode, String CauseCode) {   // @violation
   } 
///////////////////////////////////////////////////////////////////////////////////////////////
    void foo(String st,    		
             int b, 			/* Safe */   
             String dt         	/* Safe */			
            ) {}					/* Safe */
	
    void foo(String st,         
	    int b, 				 	// @violation
             String dt          /* Safe */			
			        ) {}			// @violation
	
    void foo(String st, int b, 	   
             String dt          /* Safe */			
	) {}							// @violation
///////////////////////////////////////////////////////////////////////////////////////////////
	public void setItem() {		/* Safe */
		
	}
	
	public void setItem(    ) {  // @violation
		
	}
///////////////////////////////////////////////////////////////////////////////////////////////
public void getItem(int a) {		/* Safe */

}

public void setItem1 (int a) { 	// @violation

}
public void setItem2 (			// @violation
		              int a
                     ) {

}
///////////////////////////////////////////////////////////////////////////////////////////////
}