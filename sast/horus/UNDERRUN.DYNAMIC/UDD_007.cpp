
/* UDD_007 - Function call, pointer parameter */

void UDD_007_function1(int index, int* arg) {
  arg[index] = 10;
}

void UDD_007_function2() {
  int* arr = new int[10];
  if(arr == 0) {
    return;
  }
  UDD_007_function1(1, arr); //It's ok.
  UDD_007_function1(-2, arr); //@violation UNDERRUN.DYNAMIC
  delete[] arr;
}
