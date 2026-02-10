// Checker: BAD_INDENTATION.DO_STATEMENT
class foo {
	public void test(){
		do {				/* Safe */
			do{				// @violation
				do
				{

	 			}while(1);
			} while(1);
	} while(1);

		do
		{

		}  while(1);

		do {					/* Safe */

		}while(1);

		do{					// @violation

		}	while(1);
	}
}