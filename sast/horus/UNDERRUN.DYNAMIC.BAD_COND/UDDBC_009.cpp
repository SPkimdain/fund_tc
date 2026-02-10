
/* UDDBC_009 - Function call, deep depth */
bool UDDBC_009_function1(bool flag, int* value, int index) {
  if(flag == false) {
    value[index] = 100;
    return true;
  }
  return false;
}


bool UDDBC_009_function2(int* value, int index) {
  return UDDBC_009_function1(false, value, index);
}

void UDDBC_009_function3(bool flag, int* data1, int* data2, int index) {
  if(flag == true) {
    UDDBC_009_function2(data1, index);
  }
  else{
    UDDBC_009_function2(data2, index);
  }
}

int UDDBC_009_function4(int index) {
  int* data1 = new int[10];
  if(data1 == 0) {
    return 0 ;
  }

  int* data2 = new int[5];
  if(data2 == 0) {
    return 0;
  }
  if(index >= -5 && index <= 8)  { // [-5, 8]
    UDDBC_009_function3(true, data1, data2, index); //@violation UNDERRUN.DYNAMIC.BAD_COND
  }

  delete[] data1;
  delete[] data2;

  return 0;
}


