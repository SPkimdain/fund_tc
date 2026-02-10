
/* TOBC_008 - Function call, return value */
struct TOBC_008_Struct {
  int value[12];
};

int TOBC_008_function1(int flag) {
  if(flag > 10) {
    return 10;
  }
  else {
    return 0;
  }
}

void TOBC_008_function2(int index) {
  TOBC_008_Struct obj;
  if(index >= 0 && index < 7) { //[0, 6]
    int offset = TOBC_008_function1(5); // 0
    obj.value[index + offset] = 10; //It's ok.

    offset = TOBC_008_function1(20); // 10
    obj.value[index + offset] = 30; //@violation TYPE_OVERRUN.BAD_COND
  }
}
