
/* ND_007 - Function call, pointer parameter */

void ND_007_function1(int* arg, int* arg2) {
  if(arg2 != 0) {
    *arg2 = 10; /* It's ok. */
  }
  *arg = 10; 
}

void ND_007_function2() {
  int* ptr = 0;
  ND_007_function1(ptr, ptr); //@violation NULL_DEREF
}
