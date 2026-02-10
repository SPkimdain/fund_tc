/**
 * An allowed next line number is 1. 
 * @author Byungho
 *
 */
// INDENTATION.SWITCH_STATEMENT
class foo {
	public void make() {
		switch (
				a) {
		case 1:					// @violation
			a= 2;
			break;
		default:
			break;
		}

		switch (a) {				/* Safe */
			case 1:					// @violation
			a= 2;
			break;
		default:
			break;
		}

		switch (a) {				/* Safe */

		case 1:					// @violation
			a= 2;
			break;
		default:
			break;
		}

		int b = 1;
		switch (a) {				/* Safe */
		case 1:					/* Safe */
			if(b == 1) {
				switch (b) {
				case 1:
					break;
				default:
					break;
				}
			}
			break;
		default:
			break;
		}
	}
}