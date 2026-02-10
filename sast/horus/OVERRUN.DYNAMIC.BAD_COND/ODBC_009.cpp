
/* ODBC_009 - Function call, deep depth */
bool ODBC_009_function1(bool flag, int* value, unsigned index) {
  if(flag == false) {
    value[index] = 100;
    return true;
  }
  return false;
}


bool ODBC_009_function2(int* value, unsigned index) {
  return ODBC_009_function1(false, value, index);
}

void ODBC_009_function3(bool flag, int* data1, int* data2, unsigned index) {
  if(flag == true) {
    ODBC_009_function2(data1, index);
  }
  else{
    ODBC_009_function2(data2, index);
  }
}

int ODBC_009_function4(unsigned index) {
  int* data1 = new int[10];
  if(data1 == 0) {
    return 0 ;
  }

  int* data2 = new int[5];
  if(data2 == 0) {
    return 0;
  }
  if(index <= 5)  { // [0, 5]
    ODBC_009_function3(true, data1, data2, index); //It's ok.

    ODBC_009_function3(false, data1, data2, index); //@violation OVERRUN.DYNAMIC.BAD_COND
  }

  delete[] data1;
  delete[] data2;

  return 0;
}


