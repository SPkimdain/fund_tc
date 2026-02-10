
/* UDSBC_008 - Function call, return value */
int UDSBC_008_function1(int flag) {
  if(flag > 10) {
    return 5;
  }
  else {
    return 0;
  }
}

void UDSBC_008_function2(int index) {
  int value[12] = { 1, };
  if(index >= 0 && index < 7) { //[0, 6]
    int offset = UDSBC_008_function1(5); // 0
    value[index + offset] = 10; //It's ok.

    offset = UDSBC_008_function1(20); // [-5, 1]
    value[index - offset] = 30; //@violation UNDERRUN.STATIC.BAD_COND
  }
}
