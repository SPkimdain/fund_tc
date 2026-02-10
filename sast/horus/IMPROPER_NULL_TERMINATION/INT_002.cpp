#include <stdlib.h>
#include <string.h>

/* INT_002 - simple case */
char* INT_002_get(int size) {
  return new char[size];
}

void INT_002_function() {
  char src[] = "abcd"; //4 + 1
  char dst1[5];
  
  
  char* dst2 = INT_002_get(4);

  strncpy(dst1, src, sizeof(src)); //It's ok.

  int size = strlen(src);
  
  strncpy(dst2, src, size); //@violation IMPROPER_NULL_TERMINATION

  delete[] dst2;
}
