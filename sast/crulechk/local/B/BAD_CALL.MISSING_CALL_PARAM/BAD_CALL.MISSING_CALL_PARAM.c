// @checker BAD_CALL.MISSING_CALL_PARAM

extern void memcpy_API11(const char * str1, const char * str2, unsigned int uint);
extern unsigned int strlen_API11(const char * str);

void Func_BCMISSINGCP_001_function(const char * x, const char * y) {	
	memcpy_API11(x, y, 1); // @violation BAD_CALL.MISSING_CALL_PARAM
	memcpy_API11(x, y, strlen_API11(x));
	
	// Do something ...
}
