
/* OSBC_009 - Function call, deep depth */
bool OSBC_009_function1(bool flag, int* value, unsigned index) {
  if(flag == false) {
    value[index] = 100;
    return true;
  }
  return false;
}


bool OSBC_009_function2(int* value, unsigned index) {
  return OSBC_009_function1(false, value, index);
}

void OSBC_009_function3(bool flag, int* data1, int* data2, unsigned index) {
  if(flag == true) {
    OSBC_009_function2(data1, index);
  }
  else{
    OSBC_009_function2(data2, index);
  }
}

int OSBC_009_function4(unsigned index) {
  int data1[10] = { 0, };
  int data2[5] = { 1, };
  if(index <= 5)  { // [0, 5]
    OSBC_009_function3(true, data1, data2, index); //It's ok.

    OSBC_009_function3(false, data1, data2, index); //@violation OVERRUN.STATIC.BAD_COND
  }

  return 0;
}


