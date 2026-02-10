
/* UDDBC_012 - functions */
void UDDBC_012_function1(int index) {
  int* arg = new int[10];
  if(arg == 0) {
    return;
  }

  arg[index] = 10;

  delete[] arg;
}

int UDDBC_012_function2(int value, bool flag) {
  if(flag == true) {
    return value + 5;
  }
  else {
    return value;
  }
}

void UDDBC_012_function3(int idx) {
  if(idx >= 0 && idx < 5) { //[0, 4]
    idx--;
    UDDBC_012_function1(UDDBC_012_function2(idx, true)); //It's ok.

    UDDBC_012_function1(UDDBC_012_function2(idx, false)); //@violation UNDERRUN.DYNAMIC.BAD_COND
  }
}
