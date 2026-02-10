// @checker BAD_FUNCTION_ADDRESSING



void foo(void);

void func()
{
	if(foo == 0) { // @violation BAD_FUNCTION_ADDRESSING

	}

	if(foo)	// @violation BAD_FUNCTION_ADDRESSING
	{
	}

	if(&foo == 1){
	}
}
