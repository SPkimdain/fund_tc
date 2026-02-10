// @checker BAD_CALL.FORBIDDEN.VARARGS

extern void memcpy_API14(const char * str1, const char * str2) {};

void Func(const char * x) {	
	memcpy_API14(x, "hardcoded"); // @violation BAD_CALL.FORBIDDEN.VARARGS
	
	// Do something ...
}

int main()
{
	return 0;
}
