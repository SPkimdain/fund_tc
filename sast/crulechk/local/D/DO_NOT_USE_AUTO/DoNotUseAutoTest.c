//@checker DO_NOT_USE_AUTO
int DoNotUseAuto_func1()
{
	auto int a = 10;  // @violation DO_NOT_USE_AUTO	
    auto float b = 3.14;  // @violation DO_NOT_USE_AUTO	
    auto char c = 'A';  // @violation DO_NOT_USE_AUTO	

	return 1;
}