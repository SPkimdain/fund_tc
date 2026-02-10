//@checker DO_NOT_USE_MODULAR

void DoNotUseModular()
{
	int mod;
	int a = 3;
	int b = 2;
	mod = a % b; //@violation DO_NOT_USE_MODULAR
}