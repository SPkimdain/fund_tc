
/* OSBC_012 - functions */
void OSBC_012_function1(int index) {
  int arg[10] = { 0, };
  arg[index] = 10;
}

unsigned OSBC_012_function2(unsigned value, bool flag) {
  if(flag == true) {
    return value + 5;
  }
  else {
    return value;
  }
}

void OSBC_012_function3(int idx) {
  if(idx < 9) { //[min, 9]
    OSBC_012_function1(OSBC_012_function2(idx, false)); //It's ok.

    OSBC_012_function1(OSBC_012_function2(idx, true)); //@violation OVERRUN.STATIC.BAD_COND
  }
}
