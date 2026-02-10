
/* ODBC_012 - functions */
void ODBC_012_function1(int index) {
  int* arg = new int[10];
  if(arg == 0) {
    return;
  }

  arg[index] = 10;

  delete[] arg;
}

unsigned ODBC_012_function2(unsigned value, bool flag) {
  if(flag == true) {
    return value + 5;
  }
  else {
    return value;
  }
}

void ODBC_012_function3(int idx) {
  if(idx < 9) { //[min, 8]
    ODBC_012_function1(ODBC_012_function2(idx, false)); //It's ok.

    ODBC_012_function1(ODBC_012_function2(idx, true)); //@violation OVERRUN.DYNAMIC.BAD_COND
  }
}
