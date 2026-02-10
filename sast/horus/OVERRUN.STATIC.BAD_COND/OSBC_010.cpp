
/* OSBC_010 - trace value */
int OSBC_010_function1(int arg) {
  return ++arg;
}

void OSBC_010_function2(unsigned index) {
  char ch = 'a';
  char dst1[10] = { 0, };
  char dst2[4] = { 0, };

  if(index < 4) { // [0, 3]
    index = OSBC_010_function1(index); // [1, 4]
    index = OSBC_010_function1(index); // [2, 5]    
    
    dst1[index] = ch; //It's ok.

    dst2[index] = ch; //@violation OVERRUN.STATIC.BAD_COND
  }
}


