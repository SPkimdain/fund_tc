package cc;

public class BadIndentationBlock {

    int field;
        int field2; // @violation

        public void bad() { // @violation
            // Do something ...
        }

    public void func(int p, int q) {
        int a = 0;
            int b = 0; // @violation

        if(p > q) { 
            a = a + 1;		/* Safe */
                b = b + 1; 	// @violation
            c = c + 1; 		/* Safe */
        } else if(p == q) {
            a = -1;
        } else {
        b = -1; 			// @violation
        }
        
        for(int i=0; i < 10; i++) {
            a = a + 1;		/* Safe */
               b = b + 1; 	// @violation
           c = c + 1; 		// @violation
        }
        
        while(1) {
        a = a + 1;		    // @violation
               b = b + 1; 	// @violation
           c = c + 1; 		// @violation
        }
        
        try {
            b = b + 1;				/* Safe */
            if(1) {					/* Safe */
                a = a + 1;		/* Safe */
            b = b + 1; 			// @violation
                c = c + 1; 		/* Safe */
            } else {
            a = a + 1;		    // @violation
            }
        } catch (Exception e) {
              a = a + 1;		/* Safe */
            b = b + 1; 			// @violation
              c = c + 1; 		/* Safe */
        }
    }
}