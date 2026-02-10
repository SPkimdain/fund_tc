//@checker AT_LEAST_ONE_EXCEPTION_HANDLER

int main(int argc, char** argv)
{
	try{
		int x= 5;
		x ++;
		
	}
	catch( int a )
	{
		a ++;
	}
	catch( ... )
	{
		
	}
	return 0;
}