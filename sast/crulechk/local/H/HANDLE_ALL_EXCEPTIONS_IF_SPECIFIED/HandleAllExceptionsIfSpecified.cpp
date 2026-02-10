//@checker HANDLE_ALL_EXCEPTIONS_IF_SPECIFIED
void HNAEXISPEC_001_function(int a) throw (int){
	if(a > 10)
	{

	}
	else{
		throw int();
	}	
}


void HNAEXISPEC_001_function2()
{
	throw int();	
}

void HNAEXISPEC_001_functio3(int b) throw(float)
{
	if(b > 5)
	{
		throw float();
	}
	else{
		try{
			throw int();
		}
		catch(...){
		}
	}
}

void HNAEXISPEC_001_functio4(int c) throw(int)
{
	if(c>5)
	{
		try{
			throw float();		 //@violation HANDLE_ALL_EXCEPTIONS_IF_SPECIFIED
		}
		catch(int e)
		{
			; //......
		}
	}
}