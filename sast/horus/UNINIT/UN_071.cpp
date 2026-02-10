#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdexcept>

#ifdef _WIN32

#define ALLOCA _alloca

#else

#include <alloca.h>

#define ALLOCA alloca

#endif

/* UN_071 - allocation, loop2 */
void UN_071_function3() {
  double* data;
  try {
    data = (double*)ALLOCA(10 * sizeof(double));
    
    for(int i = 0; i < 10; i++) {
      printf("%ld", data[i]); //@violation UNINIT
    }
  }
  catch(std::exception& ex) {
    //...
  }

  return;
}
