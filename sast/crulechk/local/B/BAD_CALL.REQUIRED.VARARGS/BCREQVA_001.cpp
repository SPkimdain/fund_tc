//@checker BAD_CALL.REQUIRED.VARARGS
extern void memcpy_API15(const char *, const char *);

void BCREQVA_001_function(const char * x) {       
  memcpy_API15("test", "hardcoded"); //@violation BAD_CALL.REQUIRED.VARARGS
}

