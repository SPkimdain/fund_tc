// @checker BAD_COMPARE
int do_xyz(void); 

int do_xyzzz(int a);
 
int f(void) {	
	/* ... */
	if (do_xyz == 0) { //@violation	BAD_COMPARE
	return -1; /* Indicate failure */
	}
	else if (do_xyzzz == 0 ) //@violation	BAD_COMPARE
	{
			return -2; /* Indicate failure */
	}
	/* ... */
	return 0;
} 

int foo() {
	if(do_xyzzz)	//@violation	BAD_COMPARE
	{
		return 0;
	}
	
	return 1;
}
