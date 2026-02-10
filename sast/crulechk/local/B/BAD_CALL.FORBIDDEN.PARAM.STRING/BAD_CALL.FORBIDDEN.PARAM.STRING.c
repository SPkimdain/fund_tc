// @checker BAD_CALL.FORBIDDEN.PARAM.STRING

#define PDB_ERRORNUM_API08 0

extern void memcpy_API09(const char * str1, const char * str2) {};

void Func(const char * x) {	
	memcpy_API09(x, "hardcoded"); // @violation BAD_CALL.FORBIDDEN.PARAM.STRING
	
	// Do something ...
}

int main()
{
	return 0;
}