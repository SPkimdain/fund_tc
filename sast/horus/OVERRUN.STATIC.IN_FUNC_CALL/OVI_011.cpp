#include <string.h>

/* OVI_011 - global variable */
char OVI_011_Buf[5] = { 0, };

void OVI_011_function() {
  char src[] = "abcde"; // sizeof(src) == 6
  strcpy(OVI_011_Buf, src); //@violation OVERRUN.STATIC.IN_FUNC_CALL
}
