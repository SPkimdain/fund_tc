
/* UDDBC_017 - range size, range index */
int* UDDBC_017_function1(int size) {
  return new int[size + 1];
}

void UDDBC_017_function2(int* arr, int index) {
  arr[index] = 10;
}

void UDDBC_017_function3(int size, int index) {
  int* arr = 0;
  if(size < 10) {
    arr = UDDBC_017_function1(size);
  }

  if(index >= 0) { //[0, max]
    UDDBC_017_function2(arr, index - 1); //@violation UNDERRUN.DYNAMIC.BAD_COND
  }

  delete[] arr;
}


