
/* LM_015 - throw1 */
enum LM_015_CEKind {
  CE_NORMAL,
  CE_DIV_BY_ZERO
};

struct LM_015_CustomException {
  LM_015_CustomException(LM_015_CEKind kind) : errorCode(kind) {}

  LM_015_CEKind errorCode;
};

void LM_015_function(int div) {
  int* ptr = new int[10];
 
  if(div == 0) { 
    /* throw and leak ptr. */
    throw LM_015_CustomException(CE_DIV_BY_ZERO); 
  } //@violation LEAK.MEMORY

  /* do something. */

  delete[] ptr;
} 

