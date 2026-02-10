
/* UDDBC_007 - Function call, pointer parameter */
void UDDBC_007_function1(int index, int arg[]) {
  arg[index] = 10;
}

void UDDBC_007_function2(int index) {
  int* arr = new int[10];
  if(arr == 0) {
    return;
  }

  if(index < 8) {
    UDDBC_007_function1(index, arr); //It's ok.
  }
  
  if(index >= 0) {
    UDDBC_007_function1(index - 2, arr); //@violation UNDERRUN.DYNAMIC.BAD_COND
  }

  delete[] arr;
}
