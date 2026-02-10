#include <stdlib.h>

/* UAF_007 - Function call, pointer parameter */
void UAF_007_function1(int flag, int* arg) {
  if(flag == true) {
    free(arg);
  }
  *arg = 10; //@violation USE_AFTER_FREE
}

void UAF_007_function2() {
  int* ptr = (int*)malloc(4);

  if(ptr == 0) {
    return;
  }

  UAF_007_function1(false, ptr); //It's ok.
  UAF_007_function1(true, ptr); 
}
