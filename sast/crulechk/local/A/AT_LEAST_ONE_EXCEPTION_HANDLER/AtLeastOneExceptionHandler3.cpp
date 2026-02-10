//@checker AT_LEAST_ONE_EXCEPTION_HANDLER

int main(int argc, char** argv)
{
	try   //@violation AT_LEAST_ONE_EXCEPTION_HANDLER
	{
	  int x = 5;
	  x++;
	}
	catch(int x)
	{
	}
	return 0;
}