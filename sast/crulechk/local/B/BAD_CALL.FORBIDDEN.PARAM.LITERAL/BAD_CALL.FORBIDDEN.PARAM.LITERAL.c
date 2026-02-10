// @checker BAD_CALL.FORBIDDEN.PARAM.LITERAL

extern void memset_API13(const char * str, unsigned int uint1, unsigned int uint2) {};

void Func(const char * x) {	
	memset_API13("hardcoded", 0, 9); // @violation BAD_CALL.FORBIDDEN.PARAM.LITERAL
	
	// Do something ...
}

int main()
{
	return 0;
}