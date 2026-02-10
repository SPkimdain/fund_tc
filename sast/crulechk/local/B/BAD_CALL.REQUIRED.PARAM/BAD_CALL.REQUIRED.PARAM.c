// @checker BAD_CALL.REQUIRED.PARAM

// Dummy functions
extern void divide(int x) {};

void Func(int x) {
	divide(x); // @violation BAD_CALL.REQUIRED.PARAM
	
	// Do something ...
}

int main()
{
	return 0;
}