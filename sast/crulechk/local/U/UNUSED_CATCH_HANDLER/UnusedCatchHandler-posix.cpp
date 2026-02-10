//@checker UNUSED_CATCH_HANDLER
void zoo() throw (int){
	throw 10;
}
void bar() throw(float){
	throw 1.0f;
}
void foo()
{
	try{
		zoo();
		bar();
	}
	catch(int e11){
	}
	catch(float e12){
	}
	
	try{
		bar();	
	}
	catch(float f1)
	{
	}
	catch(int e21)	//@violation	UNUSED_CATCH_HANDLER
	{
	}
	catch(short e21)	//@violation	UNUSED_CATCH_HANDLER
	{
	}
	catch(...)
	{
	}


	/*
	try{
		zoo();	
	}
	catch(...){
	}
	catch(int e31)	//By EDG	UNUSED_CATCH_HANDLER
	{
	}*/
}
