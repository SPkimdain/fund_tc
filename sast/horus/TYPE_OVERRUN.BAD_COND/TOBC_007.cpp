
/* TOBC_007 - Function call, pointer parameter */
struct TOBC_007_Struct {
  int arr[10];
};

void TOBC_007_function1(int index, int arg[]) {
  arg[index] = 10;
}

void TOBC_007_function2(unsigned index) {
  TOBC_007_Struct obj;
  if(index < 8) {
    TOBC_007_function1(index, obj.arr); //It's ok.
  }
  
  if(index < 11) {
    TOBC_007_function1(index, obj.arr); //@violation TYPE_OVERRUN.BAD_COND
  }
}
