/**
 * An allowed white space number is 1. 
 * @author Byungho
 *
 */

class foo {
	public void make() {
		switch ( ((a+2)-3) ) {   		 	/* Safe */
		}
		switch( ((a+2)-3) ) {   		 		// @violation
		}
		switch (((a+2)-3) ) {   		 		// @violation
		}
		switch ( ((a+2)-3)) {   		 		// @violation
		}
	}
}