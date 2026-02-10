#include <memory.h>
#include <stdlib.h>

/* CAOM_001 - simple case */
extern void *aligned_alloc(size_t alignment, size_t size);

void CAOM_001_function() {

  size_t resize = 1024;
  size_t alignment = 1 << 12;
  int *ptr;
  int *ptr1;
  if((ptr = (int*)aligned_alloc(alignment, sizeof(int))) == NULL) {
    /* handle error */
    return;
  }
  if((ptr1 = (int*)realloc(ptr, resize)) == NULL) {  //@violation CHECK_ALIGNMENT_OF_MEMORY
    /* handle error */
    free(ptr);
    return;
  }

  free(ptr1);
}
