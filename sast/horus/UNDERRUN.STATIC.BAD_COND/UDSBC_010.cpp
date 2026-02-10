
/* UDSBC_010 - trace value */
int UDSBC_010_function1(int arg) {
  return ++arg;
}

void UDSBC_010_function2(int index) {
  char ch = 'a';
  char dst1[10] = { 0, };
  char dst2[4] = { 0, };

  if(index >= -10 && index < 0) { // [-10, -1]
    index = UDSBC_010_function1(index); // [-9, 0]
    index = UDSBC_010_function1(index); // [-8, 1]    

    dst2[index] = ch; //@violation UNDERRUN.STATIC.BAD_COND
  }
}


