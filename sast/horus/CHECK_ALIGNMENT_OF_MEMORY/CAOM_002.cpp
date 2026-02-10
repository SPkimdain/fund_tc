#include <memory.h>
#include <stdlib.h>

/* CAOM_002 - simple case */
extern void *aligned_alloc(size_t alignment, size_t size);

int* CAOM_002_get() {
  size_t alignment = 1 << 12;
  int* ptr = (int*)aligned_alloc(alignment, sizeof(int));
  return ptr;
}

void CAOM_002_function2() {

  size_t resize = 1024;
  size_t alignment = 1 << 12;
  int *ptr = CAOM_002_get();
  if(ptr == 0) {
    return;
  }
  
  int *ptr1;
  if((ptr1 = (int*)realloc(ptr, resize)) == NULL) {  //@violation CHECK_ALIGNMENT_OF_MEMORY
    /* handle error */
    free(ptr);
    return;
  }

  free(ptr1);
}
