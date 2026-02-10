/**
 * An allowed white space number is 1. 
 * @author Byungho
 *
 */

class foo {
	public void make() {
		try {
		} catch ( Exception e ) {		/* Safe */
		}
		
		try {
		} catch( Exception e ) {			// @violation
		}
		
		try {
		} catch (Exception e ) {			// @violation
		}
		
		try {
		} catch ( Exception e) {			// @violation
		}
	}
}