
/* ODBC_017 - range size, range index */
int* ODBC_017_function1(int size) {
  return new int[size + 1];
}

void ODBC_017_function2(int* arr, int index) {
  arr[index] = 10;
}

void ODBC_017_function3(int size, int index) {
  int* arr = 0;
  if(size < 10) {
    arr = ODBC_017_function1(size);
  }

  if(index <= 11) {
    ODBC_017_function2(arr, index); //@violation OVERRUN.DYNAMIC.BAD_COND
  }

  delete[] arr;
}


