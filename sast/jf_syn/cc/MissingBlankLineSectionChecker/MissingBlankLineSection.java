package cc;

public class MissingBlankLineSection {

    public int iFunc() {
        int a;				
        
        for(i=0;i<2;i++) {	
        	b=2;
        }					/* Safe */
        
        if(1) {				
        	a=1;
        }					/* Safe */

        // comment
        while(1) {			
        	
        }					/* Safe */
        
        if(1) {			   
			
        	if(1) {				
				a = 2;
			}					// @violation
			while(1) {			
	        	
	        }
        }						// @violation
        
        
        try {
        	
        }						/* Safe */

        return a;
    }
}
