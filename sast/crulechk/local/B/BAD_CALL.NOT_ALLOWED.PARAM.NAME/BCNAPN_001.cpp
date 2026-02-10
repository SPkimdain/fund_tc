//@checker BAD_CALL.NOT_ALLOWED.PARAM.NAME
#define API03_COUNTER "allowed"

extern void memcpy_API03(const char *, const char *);

void Fun_BCNAPN_001_function(const char * x) {        
  memcpy_API03(x, API03_COUNTER); //@violation BAD_CALL.NOT_ALLOWED.PARAM.NAME
}


