// @checker NON_CONSTANT_PTR_TO_FUNCTION

struct Test {
	int value;
	int value2;	
};

typedef int* (*fpType)(int*, double, const Test*);

extern int value20;

int NCPTRTF_001_function104a ( void ) 
{
	return 1;
}

int NCPTRTF_001_function104b ( void ) 
{
	return 1;
}

float NCPTRTF_001_function104c(int a) {
	return (float)a + 10.F;
}

void NCPTRTF_001_function(int foo)	
{
	static int x = 0;
	int ( *const fp )  ( void )  = NCPTRTF_001_function104a;
	int ( *fp1 )  ( void )  = NCPTRTF_001_function104b;		//@violation NON_CONSTANT_PTR_TO_FUNCTION
	float (*fpName)(int) = NCPTRTF_001_function104c; //@violation NON_CONSTANT_PTR_TO_FUNCTION
}
