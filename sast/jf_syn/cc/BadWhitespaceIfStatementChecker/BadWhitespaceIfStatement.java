/**
 * An allowed white space number is 1. 
 * @author Byungho
 *
 */

class foo {
	public void make() {
		if /* comment */( a==2 ) {   /* Safe */
		}
		if( a==2 ) {   		 		// @violation
		}
		if (a==2 ) {   		 		// @violation
		}
		if ( a==2) {   		 		// @violation
		}
		
		if ( (a==1) && (b==2) ) {	/* Safe */
		}
		if( (a==1) && (b==2) ) {		// @violation
		}
		if ((a==1) && (b==2) ) {		// @violation
		}
		if ( (a==1) && (b==2)) {		// @violation
		}
		
		if ( (a==1) && (b==2) ) {		/* Safe */
			if ( (a==1) && (b==2) ) {	/* Safe */
			}
			if( (a==1) && (b==2) ) {		// @violation
			}
			if ((a==1) && (b==2) ) {		// @violation
			}
			if ( (a==1) && (b==2)) {		// @violation
			}
		}
		
		if( (a==1) && (b==2) ) {			// @violation
			if ( (a==1) && (b==2) ) {	/* Safe */
			}
			if( (a==1) && (b==2) ) {		// @violation
			}
			if ((a==1) && (b==2) ) {		// @violation
			}
			if ( (a==1) && (b==2)) {		// @violation
			}
		}
	}
}