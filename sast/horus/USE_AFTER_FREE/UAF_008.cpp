#include <stdlib.h>

/* UAF_008 - Function call, call by reference */
void UAF_008_function1(int* arg, int flag, int** output) {
  if(flag > 10) {    
    *output = arg;
  }
  else {
    free(arg);
    *output = arg;
  }
}

void UAF_008_function2() {
  int* x = (int*)malloc(4);

  if(x == 0) {
    return;
  }

  int* ptr = 0;
  UAF_008_function1(x, 15, &ptr);
  *ptr = 10; //It's ok.
  UAF_008_function1(x, 5, &ptr);

  *ptr = 10; //@violation USE_AFTER_FREE
}
