#include <stdlib.h>
#include <string.h>

/* INT_001 - simple case */

void INT_001_function() {
  char src[] = "abcd"; //4 + 1
  char dst1[5];
  char dst2[4];

  strncpy(dst1, src, sizeof(src)); //It's ok.

  int size = strlen(src);
  strncpy(dst2, src, size); //@violation IMPROPER_NULL_TERMINATION

}
