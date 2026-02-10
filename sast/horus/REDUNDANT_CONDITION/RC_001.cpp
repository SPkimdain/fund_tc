//@checker REDUNDANT_CONDITION
int RC_function_001(int flag){

	int a = 0;
	int b = 1;

	if(a == 0) //@violation REDUNDANT_CONDITION
	{
		return 1;
	}
	return 0;
}