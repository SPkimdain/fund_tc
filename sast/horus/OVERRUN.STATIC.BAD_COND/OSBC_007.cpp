
/* OSBC_007 - Function call, pointer parameter */
void OSBC_007_function1(int index, int arg[]) {
  arg[index] = 10;
}

void OSBC_007_function2(unsigned index) {
  int arr[10] = { 1, };
  if(index < 8) {
    OSBC_007_function1(index, arr); //It's ok.
  }
  
  if(index < 11) {
    OSBC_007_function1(index, arr); //@violation OVERRUN.STATIC.BAD_COND
  }
}
