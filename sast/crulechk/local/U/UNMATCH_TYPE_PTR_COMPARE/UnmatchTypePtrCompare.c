// @checker UNMATCH_TYPE_PTR_COMPARE

enum { SIZE = 32 };


void func_bar(void)
{
	int ss1[10];
	int ss2[10];

	int *ss1_ptr = &ss1[0];
	int *ss2_ptr = &ss2[0];

	if (ss1_ptr > ss2_ptr)	//@violation UNMATCH_TYPE_PTR_COMPARE
	{
	  /* ... */ 
	};
}
