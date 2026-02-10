class foo {
	public void make() {
			try {
		} catch ( Exception e ) { // @violation
		}
			
		try {
		} 
		catch ( Exception e ) { /* SAFE */
		}
		
		try {
		} 
		catch ( Exception e ) {		/* SAFE */
		} finally {					// @violation
			
		}
		
		try {
		} catch ( Exception e ) {		// @violation
		} finally {						// @violation
			
		}

		try {
		}
		    catch ( Exception e ) {			// @violation
		}
		finally {						/* SAFE */
			
		}
	}
}
