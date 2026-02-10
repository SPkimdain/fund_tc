//@checker FORBIDDEN_CALL.BEFORE_CALL

void umask_FBD16();
void fopen_FBD16(const char *, const char *);

void FuncFBDCBFRC_001_function(int x) {
  umask_FBD16();  //@violation FORBIDDEN_CALL.BEFORE_CALL
  fopen_FBD16("file.txt", "r"); 
}
