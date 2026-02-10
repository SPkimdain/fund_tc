#include <memory.h>

/* ND_020 - library test */
void ND_020_function() {
  const char src[] = "abc";
  char* dst = 0;
  int size = sizeof(src);

  memcpy(dst, src, size); //@violation NULL_DEREF
    
}

