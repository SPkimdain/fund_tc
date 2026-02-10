//@checker UNUSED_PARAMETER
int UNUSEDPARAM_001_function1(char const * bb)
{
	int a= 1;
	char * cc = bb;
	return a;
}

void UNUSEDPARAM_001_function2(char const *a, int b) {
	int x = 0;
	x = (b & 1) ? -1 : 0;
	int c= 0;
	c = UNUSEDPARAM_001_function1(a);
	/* some code*/
}


void UNUSEDPARAM_001_function3()
{
  UNUSEDPARAM_001_function2("test",5);
}
