
/* OSBC_008 - Function call, return value */
int OSBC_008_function1(int flag) {
  if(flag > 10) {
    return 10;
  }
  else {
    return 0;
  }
}

void OSBC_008_function2(int index) {
  int value[12] = { 1, };
  if(index >= 0 && index < 7) { //[0, 6]
    int offset = OSBC_008_function1(5); // 0
    value[index + offset] = 10; //It's ok.

    offset = OSBC_008_function1(20); // 10
    value[index + offset] = 30; //@violation OVERRUN.STATIC.BAD_COND
  }
}
