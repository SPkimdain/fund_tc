//@checker REDUNDANT_CONDITION

int RC_func_called1(){
	return 1;
}

int RC_func_called2(){
	return 0;
}

int RC_function_002(){

	int x = RC_func_called1();
	int y = RC_func_called2();

	if(x==0||y==0) //@violation REDUNDANT_CONDITION
	{
		return 1;
	}
	return 0;
}