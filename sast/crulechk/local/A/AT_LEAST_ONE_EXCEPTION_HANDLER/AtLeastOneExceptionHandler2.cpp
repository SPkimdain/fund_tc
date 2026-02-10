//@checker AT_LEAST_ONE_EXCEPTION_HANDLER

int main(int argc, char** argv) //@violation AT_LEAST_ONE_EXCEPTION_HANDLER
{
	int x = 5;
	x++;
	
	return 0;
}