
/* TUDBC_008 - Function call, return value */
struct TUDBC_008_Struct {
  int value[12];
};

int TUDBC_008_function1(int flag) {
  if(flag > 10) {
    return 5;
  }
  else {
    return 0;
  }
}

void TUDBC_008_function2(int index) {
  TUDBC_008_Struct obj;
  if(index >= 0 && index < 7) { //[0, 6]
    int offset = TUDBC_008_function1(5); // 0
    obj.value[index + offset] = 10; //It's ok.

    offset = TUDBC_008_function1(20); // [-5, 1]
    obj.value[index - offset] = 30; //@violation TYPE_UNDERRUN.BAD_COND
  }
}
