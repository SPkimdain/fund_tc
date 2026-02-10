
/* UDSBC_009 - Function call, deep depth */
bool UDSBC_009_function1(bool flag, int* value, int index) {
  if(flag == false) {
    value[index] = 100;
    return true;
  }
  return false;
}


bool UDSBC_009_function2(int* value, unsigned index) {
  return UDSBC_009_function1(false, value, index);
}

void UDSBC_009_function3(bool flag, int* data1, int* data2, int index) {
  if(flag == true) {
    UDSBC_009_function2(data1, index);
  }
  else{
    UDSBC_009_function2(data2, index);
  }
}

int UDSBC_009_function4(int index) {
  int data1[10] = { 0, };
  int data2[5] = { 1, };
  if(index >= -5 && index <= 4)  { // [-5, 4]
    UDSBC_009_function3(false, data1, data2, index); //@violation UNDERRUN.STATIC.BAD_COND
  }

  return 0;
}


