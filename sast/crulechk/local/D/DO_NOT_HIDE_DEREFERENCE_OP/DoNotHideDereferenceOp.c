//@checker DO_NOT_HIDE_DEREFERENCE_OP
#define CAL(a, b) *a + *b //@violation DO_NOT_HIDE_DEREFERENCE_OP
#define CAL2(a, b) a + b

int DNHDRFOP_001_function(int* test, int* test2, int* test3)
{
	int val = 10;
  int val2 = 20;
	*test3 = CAL(test,test2);
	int c = CAL2(val, val2);
	
	return *test3;
	
}
