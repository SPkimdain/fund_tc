// @checker BAD_INTEGER_CONST_DEFINITION

const unsigned long mask = 0xFFFFFFFF;	// @violation BAD_INTEGER_CONST_DEFINITION
 
unsigned long foo(unsigned long x) {
  return x ^ mask;		
}

void bar(){
	const unsigned long mask = 0x80000000;	//@violation BAD_INTEGER_CONST_DEFINITION
	unsigned long x;
	 
	/* Initialize x */
	x = (x ^ mask) + 1;		
}
