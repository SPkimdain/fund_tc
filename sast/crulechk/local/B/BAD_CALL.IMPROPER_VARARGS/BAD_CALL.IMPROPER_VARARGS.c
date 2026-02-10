// @checker BAD_CALL.IMPROPER_VARARGS

extern void Fun_API04_call(int i, ...) {};

void Func(const char * x) {	
	int p1, p2;
	Fun_API04_call(1, p1, p2); // @violation BAD_CALL.IMPROPER_VARARGS
	
	// Do something ...
}

int main() 
{
	return 0;
}