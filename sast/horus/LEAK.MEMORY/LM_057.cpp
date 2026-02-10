#include <stdlib.h>
#include <memory.h>

/* LM_057 - global variable + assign the other function */
int* LM_057_glVar;

void* LM_057_xmalloc(size_t n) {
  void* p = malloc(n);
  if(p == 0) {
    exit(1);
  }
  return p;
}


void LM_057_function0() {
  LM_057_glVar = 0;
}

void LM_057_function1(int flag) {
  if(flag > 10) {
    LM_057_function0();
  }
}

int LM_057_function2() {
  if(LM_057_glVar == 0) {
    LM_057_glVar = (int*)LM_057_xmalloc(10);
  }
  return 0;
}

void LM_057_function3(int index) {
  if(index > 0) {
    LM_057_function2();    

    LM_057_function1(15);
  }
  
  index++;
  index++;
  return;
} //@violation LEAK.MEMORY
