 class foo {
	
	public void foo1() {
		for(i=0; 		
		    i<2; 		/* Safe */
		    i++) {		// @violation
		}
		
	}

	public void foo2() {
        for(i=0; 		
            i<2; 			/* Safe */
            i++				/* Safe */
           ) {		       /* Safe */
		}
		
	}
	
	public void foo3() {
		for(i=0; 		
		    i<2; 		/* Safe */
		i++				// @violation
              ) {		// @violation
		}
		
	}
	
	public void foo4() {
		for(
			i=0; 			
				i<2; 		// @violation
		i++					// @violation
              ) {			// @violation
		}
		
	}
}