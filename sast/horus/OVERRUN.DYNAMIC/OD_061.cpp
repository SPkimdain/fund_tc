
/* OD_061 - throw1 */
enum OD_061_CEKind {
  CE_NORMAL,
  CE_DIV_BY_ZERO
};

struct OD_061_CustomException {
  OD_061_CustomException(OD_061_CEKind kind) : errorCode(kind) {}

  OD_061_CEKind errorCode;
};

void OD_061_function(int div) {
  int* ptr = new int[10];
 
  for(int i = 0; i < 100; i++) {
    ptr[i] = (i * 100) / div;	//@violation OVERRUN.DYNAMIC
  }
  
  /* do something. */

  delete[] ptr;
} 

