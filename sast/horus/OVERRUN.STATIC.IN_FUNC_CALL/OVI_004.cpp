#include <string.h>

/* OVI_004 - simple strcpy */
void OVI_004_function() {
  char src[] = "abcde"; //sizeof(src) == 6
  char src2[] = "fghi"; //sizeof(src2) == 5
  char dst[5] = { 0, };
  strcpy(dst, src2); //It's ok.
  
  strcpy(dst, src); //@violation OVERRUN.STATIC.IN_FUNC_CALL
}
