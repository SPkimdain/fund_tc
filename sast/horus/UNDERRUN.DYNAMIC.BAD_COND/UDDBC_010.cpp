
/* UDDBC_010 - trace value */
int UDDBC_010_function1(int arg) {
  return ++arg;
}

void UDDBC_010_function2(int index) {
  char ch = 'a';
  char* dst1 = new char[10];
  if(dst1 == 0) {
    return;
  }

  char* dst2 = new char[4];
  if(dst2 == 0) {
    return;
  }

  if(index >= -10 && index < 0) { // [-10, -1]
    index = UDDBC_010_function1(index); // [-9, 0]
    index = UDDBC_010_function1(index); // [-8, 1]    
    
    dst2[index] = ch; //@violation UNDERRUN.DYNAMIC.BAD_COND
  }

  delete[] dst1;
  delete[] dst2;
}


