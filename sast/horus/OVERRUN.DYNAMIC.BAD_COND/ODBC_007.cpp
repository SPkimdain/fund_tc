
/* ODBC_007 - Function call, pointer parameter */
void ODBC_007_function1(int index, int arg[]) {
  arg[index] = 10;
}

void ODBC_007_function2(unsigned index) {
  int* arr = new int[10];
  if(arr == 0) {
    return;
  }

  if(index < 8) {
    ODBC_007_function1(index, arr); //It's ok.
  }
  
  if(index < 11) {
    ODBC_007_function1(index, arr); //@violation OVERRUN.DYNAMIC.BAD_COND
  }

  delete[] arr;
}
