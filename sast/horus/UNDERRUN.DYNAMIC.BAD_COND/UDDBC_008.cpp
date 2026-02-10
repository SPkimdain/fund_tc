
/* UDDBC_008 - Function call, return value */
int UDDBC_008_function1(int flag) {
  if(flag > 10) {
    return 3;
  }
  else {
    return 0;
  }
}

void UDDBC_008_function2(int index) {
  int* value = new int[12];
  if(value == 0) {
    return;
  }

  if(index >= 0 && index < 7) { //[0, 6]
    int offset = UDDBC_008_function1(5); // 0
    value[index + offset] = 10; //It's ok.

    offset = UDDBC_008_function1(20); // [-3, 3]
    value[index - offset] = 30; //@violation UNDERRUN.DYNAMIC.BAD_COND
  }

  delete[] value;
}
