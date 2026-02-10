//@checker BAD_CALL.REQUIRED.WRAPPER

extern int API06_NEED_WRAPPER(int);
extern int API06_WRAPPER(int);

void BCREQWRAP_001_function(const char * x) {
  int a = API06_NEED_WRAPPER(0); //@violation BAD_CALL.REQUIRED.WRAPPER
}
