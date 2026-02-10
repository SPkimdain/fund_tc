//@checker HANDLE_ALL_EXCEPTIONS_NOT_IN_SPEC
void HNAEXNISPEC_001_function(int a) throw (int){
	if(a > 10)
	{
		throw float();	//@violation HANDLE_ALL_EXCEPTIONS_NOT_IN_SPEC
	}
	else{
		
	}	
}

void HNAEXNISPEC_001_function2()
{
	throw int();	//@violation HANDLE_ALL_EXCEPTIONS_NOT_IN_SPEC
}

void HNAEXNISPEC_001_function3(int b) throw(float)
{
	if(b > 5)
	{
		
	}
	else{
		try{
			throw int();
		}
		catch(...){
		}
	}
}

void HNAEXNISPEC_001_function4(int c) throw(int)
{
	if(c>5)
	{
		try{
			throw float();		//@violation HANDLE_ALL_EXCEPTIONS_NOT_IN_SPEC
		}
		catch(int e)
		{
			; //......
		}
	}
}