//@checker EXCESSIVE_STACK_DEPTH
static char buf[65537];	//not violation
void func(){
	static int buf2[65538]; // not violation
	
}
