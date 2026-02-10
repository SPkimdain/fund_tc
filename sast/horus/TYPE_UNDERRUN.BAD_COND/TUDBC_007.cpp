
/* TUDBC_007 - Function call, pointer parameter */
struct TUDBC_007_Struct {
  int arr[10];
};

void TUDBC_007_function1(int index, int arg[]) {
  arg[index] = 10;
}

void TUDBC_007_function2(int index) {
  TUDBC_007_Struct obj;
  if(index < 8) {
    TUDBC_007_function1(index, obj.arr); //It's ok.
  }
  
  if(index >= 1) {
    TUDBC_007_function1(index - 2, obj.arr); //@violation TYPE_UNDERRUN.BAD_COND
  }
}
