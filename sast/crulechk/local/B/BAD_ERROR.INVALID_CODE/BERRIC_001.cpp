//@checker BAD_ERROR.INVALID_CODE
extern void SET_ERR_API19(const char *);

void Func_BERRIC_001_function(const char * x) {        
	SET_ERR_API19("INVALIDERR"); //@violation BAD_ERROR.INVALID_CODE
}

