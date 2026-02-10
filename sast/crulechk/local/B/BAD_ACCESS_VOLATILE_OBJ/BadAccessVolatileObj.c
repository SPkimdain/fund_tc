// @checker BAD_ACCESS_VOLATILE_OBJ

static volatile int **ipp;
static int *ip;
static volatile int i = 0;
 
void foo(){
	 
	ipp = &ip; //@violation	BAD_ACCESS_VOLATILE_OBJ
	ipp = (int**) &ip; //@violation	BAD_ACCESS_VOLATILE_OBJ
	*ipp = &i; /* valid */
	if (*ip != 0) { /* valid */
	  /* ... */
	}
}

