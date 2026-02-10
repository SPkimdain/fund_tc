//@checker BAD_CALL.FORBIDDEN.PARAM.NAME
#define API01_COUNTER "forbidden"

extern void memcpy_API01(const char *, const char*, const char *);

void Fun_BCFBDPN_001_function(const char * x) {        
  memcpy_API01(x, "test", API01_COUNTER); //@violation BAD_CALL.FORBIDDEN.PARAM.NAME

}

