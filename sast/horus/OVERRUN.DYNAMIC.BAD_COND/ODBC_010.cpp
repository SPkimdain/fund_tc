
/* ODBC_010 - trace value */
int ODBC_010_function1(int arg) {
  return ++arg;
}

void ODBC_010_function2(unsigned index) {
  char ch = 'a';
  char* dst1 = new char[10];
  if(dst1 == 0) {
    return;
  }

  char* dst2 = new char[4];
  if(dst2 == 0) {
    return;
  }

  if(index < 4) { // [0, 3]
    index = ODBC_010_function1(index); // [1, 4]
    index = ODBC_010_function1(index); // [2, 5]    
    
    dst1[index] = ch; //It's ok.

    dst2[index] = ch; //@violation OVERRUN.DYNAMIC.BAD_COND
  }

  delete[] dst1;
  delete[] dst2;
}


