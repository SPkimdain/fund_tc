
/* UDSBC_007 - Function call, pointer parameter */
void UDSBC_007_function1(int index, int arg[]) {
  arg[index] = 10;
}

void UDSBC_007_function2(int index) {
  int arr[10] = { 1, };
  if(index < 8) {
    UDSBC_007_function1(index, arr); //It's ok.
  }
  
  if(index >= 0) { //[0, max]
    UDSBC_007_function1(index - 1, arr); //@violation UNDERRUN.STATIC.BAD_COND
  }
}
