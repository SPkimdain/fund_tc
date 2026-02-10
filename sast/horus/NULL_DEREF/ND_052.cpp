
/* ND_052 - trace return values */
int ND_052_function1(int flag) {
  if(flag > 100) {
    return 1;
  }
  else{
    return 0;
  }
}

int* ND_052_function2(int flag, int* ptr) {
  int ret = ND_052_function1(flag);
  if(ret == 1) {
    return ptr;
  }
  else{
    return 0;
  }
}

void ND_052_function3() {
  int value;
  int* retPtr = 0;
  
  retPtr = ND_052_function2(99, &value);

  int x = *retPtr; //@violation NULL_DEREF
}

