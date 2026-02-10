
/* ODBC_008 - Function call, return value */
int ODBC_008_function1(int flag) {
  if(flag > 10) {
    return 10;
  }
  else {
    return 0;
  }
}

void ODBC_008_function2(int index) {
  int* value = new int[12];
  if(value == 0) {
    return;
  }

  if(index >= 0 && index < 7) { //[0, 6]
    int offset = ODBC_008_function1(5); // 0
    value[index + offset] = 10; //It's ok.

    offset = ODBC_008_function1(20); // 10
    value[index + offset] = 30; //@violation OVERRUN.DYNAMIC.BAD_COND
  }

  delete[] value;
}
