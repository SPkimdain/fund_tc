
/* OD_007 - Function call, pointer parameter */

void OD_007_function1(int index, int* arg) {
  arg[index] = 10;
}

void OD_007_function2() {
  int* arr = new int[10];
  if(arr == 0) {
    return;
  }
  OD_007_function1(1, arr); //It's ok.
  OD_007_function1(15, arr); //@violation OVERRUN.DYNAMIC
  delete[] arr;
}
