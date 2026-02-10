
/* OV_007 - Function call, pointer parameter */

void OV_007_function1(int index, int arg[]) {
  arg[index] = 10;
}

void OV_007_function2() {
  int arr[10] = { 1, };
  OV_007_function1(1, arr); //It's ok.
  OV_007_function1(15, arr); //@violation OVERRUN.STATIC
}
