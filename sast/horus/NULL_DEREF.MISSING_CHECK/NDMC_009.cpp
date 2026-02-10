
/* NDMC_009 - trace return values */
int NDMC_009_function1(int flag) {
  if(flag > 100) {
    return 1;
  }
  else{
    return 0;
  }
}

int* NDMC_009_function2(int flag, int* ptr, int* ptr2) {
  int ret = NDMC_009_function1(flag);
  if(ret == 1) {
    return ptr;
  }
  else{
    return ptr2;
  }
}

void NDMC_009_function3(int* obj) {
  int value;
  int* retPtr = 0;

  if(obj != 0) {
    *obj = 20;
  }

  retPtr = NDMC_009_function2(99, &value, obj); //retptr is ptr2.

  int x = *retPtr; //@violation NULL_DEREF.MISSING_CHECK
}

