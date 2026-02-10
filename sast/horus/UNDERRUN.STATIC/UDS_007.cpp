
/* UDS_007 - Function call, pointer parameter */

void UDS_007_function1(int index, int arg[]) {
  arg[index] = 10;
}

void UDS_007_function2() {
  int arr[10] = { 1, };
  UDS_007_function1(1, arr); //It's ok.
  UDS_007_function1(-1, arr); //@violation UNDERRUN.STATIC
}
