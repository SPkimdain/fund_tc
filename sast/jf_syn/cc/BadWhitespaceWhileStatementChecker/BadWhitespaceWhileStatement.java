/**
 * An allowed white space number is 1. 
 * @author Byungho
 * BAD_WHITESPACE.WHILE_STATEMENT
 */

class foo {
	public void make(){
		int a = 0;
		while (a==2) {	/* Safe */
		}
		while (a==2){	// @violation
		}
		while(a ==2)
		{

		}

	}
}
