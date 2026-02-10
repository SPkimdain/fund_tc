// @checker BAD_CALL.MISSING_CALL_PARAM.EXTENDED

extern void memcpy_API12(const char * str1, const char * str2, unsigned int uint);
extern unsigned int strlen_API12(const char * str);

void Func(const char * x, const char * y) {	
	memcpy_API12(x, y, strlen_API12(y)); // @violation BAD_CALL.MISSING_CALL_PARAM.EXTENDED
	memcpy_API12(x, y, strlen_API12(x));
	
	// Do something ...
}
