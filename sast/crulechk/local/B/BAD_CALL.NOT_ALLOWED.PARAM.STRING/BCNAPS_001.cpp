//@checker BAD_CALL.NOT_ALLOWED.PARAM.STRING
extern void memcpy_API02(const char *, const char *);

void Fun_BCNAPS_001_function(const char * x, const char * y) {        
  memcpy_API02(x, y);  //@violation BAD_CALL.NOT_ALLOWED.PARAM.STRING
}

