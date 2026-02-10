// @checker UNCHECK_ARRAY_LENGTH
#include "custom_typedef.h"

#define NULL 0

typedef long size_t;
extern void* malloc (size_t size);
extern void free (void* ptr);
enum { MAX_ARRAY = 1024 };

void uncheck_array_length_func1(size_t size) {//@b-violation UNCHECK_ARRAY_LENGTH
  int vla[size];	 //@violation UNCHECK_ARRAY_LENGTH
  /* ... */
}

extern void do_work(int* array, size_t size);

void uncheck_array_length_func2(size_t size) {
  if (0 < size && size < MAX_ARRAY) {
    int vla[size];	//It's ok
    do_work(vla, size);
  } else {
    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
      /* Handle error */
    }
    do_work(array, size);
    free(array);
  }
}