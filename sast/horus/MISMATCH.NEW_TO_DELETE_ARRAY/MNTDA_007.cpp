
/* MNTDA_007 - return value */
char* MNTDA_007_function1(int size){
  if(size < 100) {
    return new char('1');
  }
  else {
    return 0;
  }
}

char* MNTDA_007_function2(){
  char* ret = new char[10];
  return ret;
}

void MNTDA_007_function3(int flag) {
  char* ptr = 0;
  
  ptr = MNTDA_007_function2();
  delete[] ptr;
  
  ptr = 0;

  if(flag > 0) {
    ptr = MNTDA_007_function1(10);
    if(ptr != 0) {
      delete[] ptr; //@violation MISMATCH.NEW_TO_DELETE_ARRAY
    }
  }
}

