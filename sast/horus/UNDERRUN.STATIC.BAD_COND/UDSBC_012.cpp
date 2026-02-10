
/* UDSBC_012 - functions */
void UDSBC_012_function1(int index) {
  int arg[10] = { 0, };
  arg[index] = 10;
}

unsigned UDSBC_012_function2(unsigned value, bool flag) {
  if(flag == true) {
    return value + 5;
  }
  else {
    return value;
  }
}

void UDSBC_012_function3(int idx) {
  if(idx >= 0 && idx < 5) { //[0, 4]
    idx--; //[-1, 3]
    UDSBC_012_function1(UDSBC_012_function2(idx, true)); //It's ok. [4, 8]

    UDSBC_012_function1(UDSBC_012_function2(idx, false)); //@violation UNDERRUN.STATIC.BAD_COND
  }
}
